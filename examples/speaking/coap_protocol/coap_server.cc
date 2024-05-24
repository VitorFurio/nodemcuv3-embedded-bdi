#include "coap_server.h"

#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>

#include <coap3/coap.h>


#define COAP_LISTEN_UCAST_IP "::"

int resolve_address(coap_str_const_t *host, uint16_t port, coap_address_t *dst,
                int scheme_hint_bits) {
  int ret = 0;
  coap_addr_info_t *addr_info;

  addr_info = coap_resolve_address_info(host, port, port,  port, port,
                                        AF_UNSPEC, scheme_hint_bits,
                                        COAP_RESOLVE_TYPE_REMOTE);
  if (addr_info) {
    ret = 1;
    *dst = addr_info->addr;
  }
  coap_free_address_info(addr_info);
  return ret;
}

int coap_server() {
    coap_context_t *ctx = nullptr;
    coap_resource_t *resource = nullptr;
    int result = EXIT_FAILURE;
    coap_str_const_t *ruri = coap_make_str_const("hello");
    uint32_t scheme_hint_bits;
    coap_addr_info_t *info = nullptr;
    coap_addr_info_t *info_list = nullptr;
    coap_str_const_t *my_address = coap_make_str_const(COAP_LISTEN_UCAST_IP);
    bool have_ep = false;

    // Inicializa a biblioteca libcoap
    coap_startup();

    // Define o nível de log
    coap_set_log_level(COAP_LOG_WARN);

    // Cria o contexto CoAP
    ctx = coap_new_context(nullptr);
    if (!ctx) {
        coap_log_emerg("cannot initialize context\n");
        goto finish;
    }

    scheme_hint_bits = coap_get_available_scheme_hint_bits(0, 0, COAP_PROTO_NONE);
    info_list = coap_resolve_address_info(my_address, 0, 0, 0, 0,
                                          0,
                                          scheme_hint_bits, COAP_RESOLVE_TYPE_LOCAL);
    // Cria o(s) ponto(s) de extremidade CoAP
    for (info = info_list; info != NULL; info = info->next) {
        coap_endpoint_t *ep;

        ep = coap_new_endpoint(ctx, &info->addr, info->proto);
        if (!ep) {
            coap_log_warn("cannot create endpoint for CoAP proto %u\n",
                          info->proto);
        } else {
            have_ep = true;
        }
    }
    coap_free_address_info(info_list);
    if (have_ep == false) {
        coap_log_err("No context available for interface '%s'\n",
                     (const char *)my_address->s);
        goto finish;
    }

    // Adiciona a escuta para multicast, se apropriado
#ifdef COAP_LISTEN_MCAST_IPV4
    coap_join_mcast_group_intf(ctx, COAP_LISTEN_MCAST_IPV4, NULL);
#endif /* COAP_LISTEN_MCAST_IPV4 */
#ifdef COAP_LISTEN_MCAST_IPV4
    coap_join_mcast_group_intf(ctx, COAP_LISTEN_MCAST_IPV6, NULL);
#endif /* COAP_LISTEN_MCAST_IPV4 */

    // Cria um recurso que o servidor pode responder com informações
    resource = coap_resource_init(ruri, 0);
    coap_register_handler(resource, COAP_REQUEST_GET,
                           [](auto, auto,
                              const coap_pdu_t *request,
                              auto, coap_pdu_t *response) {
                               coap_show_pdu(COAP_LOG_WARN, request);
                               coap_pdu_set_code(response, COAP_RESPONSE_CODE_CONTENT);
                               coap_add_data(response, 5,
                                             (const uint8_t *)"world");
                               coap_show_pdu(COAP_LOG_WARN, response);
                           });
    coap_add_resource(ctx, resource);

    // Loop principal para lidar com a E/S CoAP de forma assíncrona
    while (true) {
        coap_io_process(ctx, COAP_IO_WAIT);
    }

    result = EXIT_SUCCESS;

finish:
    coap_free_context(ctx);
    coap_cleanup();

    return result;
}

//int main() {
  //  return start_coap_server();
//}

