#include "functions.h"
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include "esp_sntp.h"  // Biblioteca para NTP

#define BUTTON_PIN GPIO_NUM_4    // Pino GPIO do ESP8266 conectado ao botão (D2)
#define GREEN_LED GPIO_NUM_13      // GPIO13 (LED verde) (D7)
#define YELLOW_LED GPIO_NUM_12     // GPIO12 (LED amarelo) (D6)
#define RED_LED GPIO_NUM_14        // GPIO14 (LED vermelho) (D5)

bool fire = false;
bool print_alert = true;
bool print_alarm = true;

// Função para inicializar o NTP e sincronizar o horário
void initialize_sntp()
{
    printf("Inicializando sincronização NTP...\n");

    // Configurar o fuso horário do Brasil (UTC-3, sem horário de verão)
    setenv("TZ", "UTC+3", 1); // Define o fuso horário
    tzset();                  // Aplica o fuso horário

    // Configurar servidor NTP
    sntp_setoperatingmode(SNTP_OPMODE_POLL);
    sntp_setservername(0, "pool.ntp.org"); // Servidor NTP padrão
    sntp_init();

    // Esperar até que o tempo esteja sincronizado
    time_t now = 0;
    struct tm timeinfo = {0};
    while (timeinfo.tm_year < (2016 - 1900)) {
        printf("Aguardando sincronização NTP...\n");
        time(&now);
        localtime_r(&now, &timeinfo);
        vTaskDelay(2000 / portTICK_PERIOD_MS); // Aguarda 2 segundos
    }
    printf("Sincronização NTP concluída! Hora inicial: %02d:%02d:%02d\n",
           timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec);
}

void print_current_time()
{
    time_t now;
    struct tm timeinfo;
    time(&now);
    localtime_r(&now, &timeinfo);
    if (timeinfo.tm_year < (2016 - 1900)) {
        printf("Horário não sincronizado.\n");
        return;
    }
    printf(" - %02d:%02d:%02d\n",
           timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec);
}


void setup()
{
    // Configuração dos pinos de entrada e saída
    gpio_set_direction(BUTTON_PIN, GPIO_MODE_INPUT);
    gpio_pullup_en(BUTTON_PIN);  // Habilita pull-up interno no botão

    gpio_set_direction(GREEN_LED, GPIO_MODE_OUTPUT);
    gpio_set_direction(YELLOW_LED, GPIO_MODE_OUTPUT);
    gpio_set_direction(RED_LED, GPIO_MODE_OUTPUT);

    gpio_set_level(GREEN_LED, true);   // Acende LED verde
    gpio_set_level(YELLOW_LED, true);  // Apaga LED amarelo
    gpio_set_level(RED_LED, true);     // Apaga LED vermelho   
}

bool action_print_init()
{
    printf("Sensor1 iniciado.");
    print_current_time();
    gpio_set_level(GREEN_LED, 1);   // Acende LED verde
    gpio_set_level(YELLOW_LED, 0);  // Apaga LED amarelo
    gpio_set_level(RED_LED, 0);     // Apaga LED vermelho
    
    // Inicializar a sincronização com NTP
    initialize_sntp();
    return true;
}

bool action_trigger_alarm()
{
    if(print_alarm){
      printf("\n# ALERT! DANGEROUS CONDITION!!");
      print_current_time();
      print_alarm = false;
    }
    gpio_set_level(GREEN_LED, 0);   // Apaga LED verde
    gpio_set_level(YELLOW_LED, 0);  // Apaga LED amarelo
    gpio_set_level(RED_LED, 1);     // Acende LED vermelho
    return true;
}

bool action_print_alert()
{
   if(print_alert){
      printf("Sensor1 operando em modo alerta");
      print_current_time();
      print_alert = false;
      print_alarm = true;
    }
    gpio_set_level(GREEN_LED, 0);   // Apaga LED verde
    gpio_set_level(YELLOW_LED, 1);  // Acende LED amarelo
    gpio_set_level(RED_LED, 0);     // Apaga LED vermelho
    return true;
}

bool action_print_default()
{
    if(!print_alert){
      printf("Sensor1 operando em modo normal");
      print_current_time();
      print_alert = true;
      print_alarm = true;
    }
    gpio_set_level(GREEN_LED, 1);   // Acende LED verde
    gpio_set_level(YELLOW_LED, 0);  // Apaga LED amarelo
    gpio_set_level(RED_LED, 0);     // Apaga LED vermelho
    return true;
}

bool action_print_fire()
{
    printf("# Fogo detectado!");
    print_current_time(); 
    return true;
}

bool action_print_not_fire()
{
    printf("# Sem Fogo!");
    print_current_time(); 
    return true;
}

bool update_fire(bool var)
{
    fire = (bool)gpio_get_level(BUTTON_PIN);  // Lê o nível lógico do botão
    return fire;
}

