#include <stdio.h>
#include "pico/stdlib.h"
#include "Led.h"

#if defined RASPBERRYPI_PICO_W
#include "pico/cyw43_arch.h"
#endif

bool timerCallback(repeating_timer_t *rt)
{
    // printf("Timer callback\n");
    return true;
}

repeating_timer_t timer;

int main()
{
    stdio_init_all();

    printf("Starting...\n");
    Led_Init();

#if defined RASPBERRYPI_PICO_W
    cyw43_arch_init();
    // cyw43_arch_enable_ap_mode("ssid", "pass", CYW43_AUTH_WPA2_AES_PSK);
    cyw43_arch_enable_sta_mode();
#endif

    add_repeating_timer_ms(1000, timerCallback, NULL, &timer);

    if(cyw43_arch_wifi_connect_timeout_ms("ssid", "pass", CYW43_AUTH_WPA2_AES_PSK, 10000)) {
        printf("Failed to connect");
    } else {
        printf("Connected");
    }

    while (true)
    {
        // printf("While loop print\n");

        Led_SetState(true);
        sleep_ms(1000);

        Led_SetState(false);
        sleep_ms(1000);
    }

    return 0;
}
