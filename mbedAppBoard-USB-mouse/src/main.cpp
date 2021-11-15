// basic mouse demonstration
// For other features, see https://os.mbed.com/docs/mbed-os/v6.15/apis/usbmouse.html
// if you have the dev board,
// hook your USB to the lower Micro-USB slot
// beneath the Xbee pins area
#include "mbed.h"
#include "USBMouse.h"
 

// instance usbmouse to my_mouse
USBMouse my_mouse;
 
int main()
{
    int16_t x = 0;
    int16_t y = 0;
    int32_t radius = 10;
    int32_t angle = 0;

    while (1) {
        //will cause mouse to move in a circle
        x = cos((double)angle * 3.14 / 180.0) * radius;
        y = sin((double)angle * 3.14 / 180.0) * radius;

        //will move mouse x, y away from its previous position on the screen
        my_mouse.move(x, y);
        angle += 3;
        ThisThread::sleep_for(10);
    }
}
