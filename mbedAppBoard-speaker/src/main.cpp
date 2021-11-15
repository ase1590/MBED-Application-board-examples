// Use the speaker to output a rising tone in steps.
#include "mbed.h"

DigitalIn fire(p14);
PwmOut spkr(p26);

int main()
{
    while (1) {
        for (float i=2000.0; i<10000.0; i+=100) {
            spkr.period(1.0/i);
            spkr=0.5;
            thread_sleep_for(100);
        }
        spkr=0.0;
        while(!fire) {}
    }
}
