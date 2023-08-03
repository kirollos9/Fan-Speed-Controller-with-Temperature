#include"motor.h"
#include"lcd.h"
#include"lm35_sensor.h"
#include"adc.h"
int main(){
	uint8 temp;
	LCD_init();
	DcMotor_Init();
	ADC_ConfigType adcconfig={INT256,FCBU8};
	ADC_init(&adcconfig);
	LCD_moveCursor(1,3);
	LCD_displayString("Temp =   C");
	    while(1)
	    {

	    	temp = LM35_getTemperature();

			/* Display the temperature value every time at same position */
			LCD_moveCursor(1,9);
			if(temp >= 100)
			{
				LCD_intgerToString(temp);
			}
			else
			{
				LCD_intgerToString(temp);
				/* In case the digital value is two or one digits print space in the next digit place */
				LCD_displayCharacter(' ');
			}
			if(temp<30)
			{
				LCD_moveCursor(0,3);
				LCD_displayString("FAN IS OFF");
				DcMotor_Rotate(Cw,0);
			}
			else if((temp>=30)&&(temp<60))
			{
				LCD_moveCursor(0,3);
				LCD_displayString("FAN IS ON");
				DcMotor_Rotate(Cw,25);
			}
			else if((temp>=60)&&(temp<90))
						{
							LCD_moveCursor(0,3);
							LCD_displayString("FAN IS ON");
							DcMotor_Rotate(Cw,50);
						}
			else if((temp>=90)&&(temp<120))
						{
							LCD_moveCursor(0,3);
							LCD_displayString("FAN IS ON");
							DcMotor_Rotate(Cw,75);
						}
			else if(temp>=120)
						{
							LCD_moveCursor(0,3);
							LCD_displayString("FAN IS ON");
							DcMotor_Rotate(Cw,100);
						}
	    }
}
