#include "functions.h"

#define BUTTON_PIN GPIO_NUM_4    // Pino GPIO do ESP8266 conectado ao botão (D2)
#define GREEN_LED GPIO_NUM_13      // GPIO13 (LED verde) (D7)
#define YELLOW_LED GPIO_NUM_12     // GPIO12 (LED amarelo) (D6)
#define RED_LED GPIO_NUM_14        // GPIO14 (LED vermelho) (D5)

bool fire = false;

void setup()
{
    // Configuração dos pinos de entrada e saída
    // No ESP8266, não há necessidade de resetar o pino explicitamente.
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
    printf("Sensor1 iniciado.\n");
    gpio_set_level(GREEN_LED, 1);   // Acende LED verde
    gpio_set_level(YELLOW_LED, 0);  // Apaga LED amarelo
    gpio_set_level(RED_LED, 0);     // Apaga LED vermelho
    return true;
}

bool action_trigger_alarm()
{
    printf("\n# ALERT! DANGEROUS CONDITION!!\n");
    gpio_set_level(GREEN_LED, 0);   // Apaga LED verde
    gpio_set_level(YELLOW_LED, 0);  // Apaga LED amarelo
    gpio_set_level(RED_LED, 1);     // Acende LED vermelho
    return true;
}

bool action_print_alert()
{
    printf("Sensor1 operando em modo alerta.\n");
    gpio_set_level(GREEN_LED, 0);   // Apaga LED verde
    gpio_set_level(YELLOW_LED, 1);  // Acende LED amarelo
    gpio_set_level(RED_LED, 0);     // Apaga LED vermelho
    return true;
}

bool action_print_default()
{
    printf("Sensor1 operando em modo normal.\n");
    gpio_set_level(GREEN_LED, 1);   // Acende LED verde
    gpio_set_level(YELLOW_LED, 0);  // Apaga LED amarelo
    gpio_set_level(RED_LED, 0);     // Apaga LED vermelho
    return true;
}

bool action_print_fire()
{
    printf("# Fogo detectado!.\n");
    return true;
}

bool action_print_not_fire()
{
    printf("# Sem Fogo!.\n");
    return true;
}

bool update_fire(bool var)
{
    fire = gpio_get_level(BUTTON_PIN);  // Lê o nível lógico do botão
    return fire;
}

