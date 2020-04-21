#include "header.h"

int main (void)
{
    u8 key;

    delay_init();
    LedInit();
    BeepInit();
    KeyInit();
    LED0 = 0;					            //先点亮红灯

    while(1)
    {
        key = KeyScan(0);                   //扫描按键键值
        if(key)                             //如果有按键
        {
            switch (key)
            {
            case KEY_0_PRES:
                BEEP_IO = !BEEP_IO;
                break;
            
            case KEY_1_PRES:
                LED0    = !LED0;
                break;

            case KEY_2_PRES:
                LED1    = !LED1;
                break;

            case KEY_3_PRES:
                LED0    = !LED0;
				LED1    = !LED1;
                break;

            default:
                break;
            }
        }
		else
		{
			delay_ms(10);
		}
    }
}
