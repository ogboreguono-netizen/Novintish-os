
#include <stdint.h>

void kmain(void)
{
    volatile uint16_t *screen =
        (uint16_t *)0xB8000;

    const char message[] =
        "Welcome to Fusion OS!";

    for (int i = 0; message[i] != '\0'; i++) {
        screen[i] =
            (uint16_t)message[i] | 0x0F00;
    }

    for (;;) {
        __asm__ volatile ("hlt");
    }
}
