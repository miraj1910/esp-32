
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/ledc.h"
#include "esp_err.h"

#define PWM_GPIO        5
#define PWM_FREQ        1000
#define PWM_RESOLUTION  LEDC_TIMER_10_BIT
#define PWM_CHANNEL     LEDC_CHANNEL_0
#define PWM_TIMER       LEDC_TIMER_0
#define PWM_MODE        LEDC_HIGH_SPEED_MODE

void app_main(void)
{
    ledc_timer_config_t timer = {
        .speed_mode = PWM_MODE,
        .timer_num = PWM_TIMER,
        .duty_resolution = PWM_RESOLUTION,
        .freq_hz = PWM_FREQ,
        .clk_cfg = LEDC_AUTO_CLK
    };

    ledc_timer_config(&timer);

    ledc_channel_config_t channel = {
        .gpio_num = PWM_GPIO,
        .speed_mode = PWM_MODE,
        .channel = PWM_CHANNEL,
        .timer_sel = PWM_TIMER,
        .duty = 307,       // 30% of 1023
        .hpoint = 0
    };

    ledc_channel_config(&channel);

    while (1) {
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
