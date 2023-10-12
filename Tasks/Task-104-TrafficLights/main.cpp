#include "uop_msb.h"
using namespace uop_msb;

#define WAIT_TIME_MS 1000000 

DigitalOut red(TRAF_RED1_PIN,1);         //Note the initial state
DigitalOut amber(TRAF_YEL1_PIN,0);
DigitalOut green(TRAF_GRN1_PIN,0);

LCD_16X2_DISPLAY lcd;

int main()
{
    volatile int n;
    while(true){
    
    lcd.cls();
    lcd.puts("RED");
    wait_us(WAIT_TIME_MS * 10);

    amber = 1;
    lcd.cls();
    lcd.puts("Amber");
    wait_us(WAIT_TIME_MS * 2);

    red = 0;
    amber = 0;
    green = 1;
    lcd.cls();
    lcd.puts("Green");    
    wait_us(WAIT_TIME_MS * 10);
    green = 0;

    for(n=0; n<=3; n = n+1){
        wait_us(WAIT_TIME_MS * 2);
        amber = 1;
        lcd.cls();
        lcd.puts("Amber");
        wait_us(WAIT_TIME_MS * 2);
        amber = 0;
    }

    }
    
}
