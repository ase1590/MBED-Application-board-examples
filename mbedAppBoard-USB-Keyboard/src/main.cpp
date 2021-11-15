// basic keyboard demonstration
// For other features, see https://os.mbed.com/docs/mbed-os/v6.15/apis/usbkeyboard.html
// if you have the dev board,
// hook your USB to the lower Micro-USB slot
// beneath the Xbee pins area
#include "mbed.h"
#include "USBKeyboard.h"
 
//LED1: NUM_LOCK
//LED2: CAPS_LOCK
//LED3: SCROLL_LOCK
BusOut leds(LED1, LED2, LED3);
 
// USBKeyboard
USBKeyboard keyboard;
 
int main(void) {
    while (1) {
        thread_sleep_for(1000);
        keyboard.printf("Hello World\r\n");
        thread_sleep_for(1000);
        keyboard.media_control(KEY_VOLUME_DOWN);
        thread_sleep_for(1000);
        keyboard.key_code(KEY_CAPS_LOCK);
        leds = keyboard.lock_status(); //Light up lights on LPC according to lights on keyboard (num_lock etc)
        thread_sleep_for(1000);
        keyboard.key_code(KEY_CAPS_LOCK);
        leds = keyboard.lock_status();
        thread_sleep_for(1000);
        keyboard.key_code(KEY_CAPS_LOCK);
        keyboard.key_code('C', KEY_SHIFT);
        keyboard.printf("apital Letter c\r\n");
        leds = keyboard.lock_status();
    }
}
