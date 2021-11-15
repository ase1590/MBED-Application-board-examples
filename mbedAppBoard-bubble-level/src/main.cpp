//Uses x & y acceleration to simulate a bubble level
//on the application board LCD display
#include "mbed.h"
#include "MMA7660.h"
#include "C12832_lcd.h"

C12832_LCD lcd; //On board LCD display
MMA7660 MMA(p28, p27); //I2C Accelerometer
DigitalOut connectionLed(LED1);//Accel OK LED



int main()
{
    int x=0,y=0;
    lcd.cls(); //clear LCD screen
    if (MMA.testConnection())
        connectionLed = 1; //Accelerometer init OK
    while(1) {
        //read X,Y +/-Gs and scale for #display pixels
        x = (x + MMA.x() * 32.0)/2.0;
        y = (y -(MMA.y() * 16.0))/2.0;
        lcd.fillcircle(x+63, y+15, 3, 1); //draw bubble
        lcd.circle(63, 15, 8, 1);
        thread_sleep_for(100); //time delay
        lcd.fillcircle(x+63, y+15, 3, 0); //erase bubble
    }

}

