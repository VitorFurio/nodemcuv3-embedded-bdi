#include "functions.h"

uint8_t pos;

adc_config_t adc_config;  
uint16_t adc_data[100];

void setup()
{
  // config adc for usage
  adc_config.mode = ADC_READ_TOUT_MODE;
  adc_config.clk_div = 8;
  adc_init(&adc_config);

  // config gpio for usage
  gpio_set_direction(D0, GPIO_MODE_OUTPUT);
  gpio_set_direction(D1, GPIO_MODE_OUTPUT);
  gpio_set_direction(D2, GPIO_MODE_OUTPUT);
  gpio_set_direction(D3, GPIO_MODE_OUTPUT);
  gpio_set_direction(D4, GPIO_MODE_OUTPUT);

  // set initial position
  pos = 1;

  // reset gpio values
  gpio_set_level(D0, 1);
  gpio_set_level(D1, 0);
  gpio_set_level(D2, 0);
  gpio_set_level(D3, 0);
  gpio_set_level(D4, 0);
}

/*---------------------------------------------------------------------------*/

uint8_t action_right()
{
  printf("Moving right...\t(P1->P2)\n");
  pos = 2;
  usleep(CYCLE_DELAY);
  return 1;
}

uint8_t action_down()
{
  printf("Moving down...\t(P2->P4)\n");
  pos = 4;
  usleep(CYCLE_DELAY);
  return 1;
}

uint8_t action_up()
{
  printf("Moving up...\t(P3->P1)\n");
  pos = 1;
  usleep(CYCLE_DELAY);
  return 1;
}

uint8_t action_left()
{
  printf("Moving left...\t(P4->P3)\n");
  pos = 3;
  usleep(CYCLE_DELAY);
  return 1;
}

uint8_t action_suck()
{
  for (int i = 0; i < 5; i++)
  {
    gpio_set_level(D4, 1);
    usleep(SUCK_DELAY);
    gpio_set_level(D4, 0);
    usleep(SUCK_DELAY);
  }
  printf("It's dirty!\tSucking...\n");
  usleep(CYCLE_DELAY);
  return 1;
}

uint8_t action_empty()
{
    printf("Deposit is full!\tGoing to empty deposit...\n");
    gpio_set_level(D4, 1);
    usleep(500000);
    if (gpio_get_level(D1))
    {
      gpio_set_level(D1, 0);
      gpio_set_level(D0, 1);
      usleep(2000000);
      gpio_set_level(D1, 1);
      gpio_set_level(D0, 0);
    }
    else if (gpio_get_level(D2))
    {
      gpio_set_level(D2, 0);
      gpio_set_level(D0, 1);
      usleep(2000000);
      gpio_set_level(D2, 1);
      gpio_set_level(D0, 0);
    }
    else if (gpio_get_level(D3))
    {
      gpio_set_level(D3, 0);
      gpio_set_level(D1, 1);
      usleep(500000);
      gpio_set_level(D0, 1);
      gpio_set_level(D1, 0);
      usleep(2000000);
      gpio_set_level(D1, 1);
      gpio_set_level(D0, 0);
      usleep(500000);
      gpio_set_level(D3, 1);
      gpio_set_level(D1, 0);
    }
    usleep(500000);
    gpio_set_level(D4, 0);
    return 1;
}

/*---------------------------------------------------------------------------*/

uint8_t update_dirty()
{
  if (ESP_OK == adc_read(&adc_data[0]))
  {
    if (
       (adc_data[0] < 500 && adc_data[0] > 250) ||
       (adc_data[0] > 650)
       )
    {
      return 1;
    }
  }
  return 0;
}

uint8_t update_start()
{
  if (ESP_OK == adc_read(&adc_data[0]))
  {
    if (adc_data[0] > 500)
    {
      return 1;
    }
  }
  return 0;
}

uint8_t update_full_deposit()
{
  if (ESP_OK == adc_read(&adc_data[0]))
  {
    if (
       (adc_data[0] < 250 && adc_data[0] > 50) ||
       (adc_data[0] < 500 && adc_data[0] > 390) ||
       (adc_data[0] < 650 && adc_data[0] > 600) ||
       (adc_data[0] > 705)
       )
    {
      return 1;
    }
  }
  return 0;
}

uint8_t update_pos(uint8_t var)
{
  switch (var)
  {
    case 1:
      gpio_set_level(D0, 1);
      gpio_set_level(D1, 0);
      gpio_set_level(D2, 0);
      gpio_set_level(D3, 0);
      break;
    case 2:
      gpio_set_level(D0, 0);
      gpio_set_level(D1, 1);
      gpio_set_level(D2, 0);
      gpio_set_level(D3, 0);
      break;
    case 3:
      gpio_set_level(D0, 0);
      gpio_set_level(D1, 0);
      gpio_set_level(D2, 1);
      gpio_set_level(D3, 0);
      break;
    case 4:
      gpio_set_level(D0, 0);
      gpio_set_level(D1, 0);
      gpio_set_level(D2, 0);
      gpio_set_level(D3, 1);
      break;
    default:
      gpio_set_level(D0, 0);
      gpio_set_level(D1, 0);
      gpio_set_level(D2, 0);
      gpio_set_level(D3, 0);
      break;
  }
  return 1;
}