// sample program to display a elf and a Christmas tree animation. 
#include "mbed.h"
#include "C12832_lcd.h"
#include "Arial_9.h"
#include "Small_7.h"
#include "graphics.h"

C12832_LCD lcd;

int main()
{
    int i,s;
    lcd.cls();
    lcd.set_font((unsigned char*) Arial_9);
    s = 3;
    lcd.print_bm(bitmTree,95,0);  // print chistmas tree
    lcd.copy_to_lcd(); 
    lcd.setmode(XOR);        // XOR - a second print will erase  
    for(i = -15; i < 75; ){     
        lcd.print_bm(bitmSan1,i,2);
        thread_sleep_for(500);
        lcd.copy_to_lcd();           // update lcd  
        lcd.print_bm(bitmSan1,i,2);  // erase
        i= i+s;
        lcd.print_bm(bitmSan2,i,2);  // print next
        thread_sleep_for(500);
        lcd.copy_to_lcd();           // update lcd   
        lcd.print_bm(bitmSan2,i,2);  // erase
        i= i+s;
        lcd.print_bm(bitmSan3,i,2);  // print next 
        thread_sleep_for(500);
        lcd.copy_to_lcd();           // update lcd
        lcd.print_bm(bitmSan3,i,2);  // erase
        i= i+s;
   }
   lcd.print_bm(bitmSan3,i,2);
   lcd.set_auto_up(0);
   for(i=-20; i<5; i++){             // scrolling text
     lcd.locate(5,i);
     lcd.printf("HAPPY");
     lcd.locate(5,i+12);
     lcd.printf("XMAS");
     lcd.copy_to_lcd();
     lcd.locate(5,i);
     thread_sleep_for(200);
     lcd.printf("HAPPY");
     lcd.locate(5,i+12);
     lcd.printf("XMAS");
     lcd.copy_to_lcd();
     i=i+1;
   }  
   lcd.locate(5,i);
   lcd.printf("HAPPY");
   lcd.locate(5,i+12);
   lcd.printf("XMAS");
   lcd.copy_to_lcd();
   
}
