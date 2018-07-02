#include "LCD_Touch_Calibration.h"
#include "stdio.h"
#include "stm32f4_discovery.h"
#include "stm32f4_discovery_lcd.h"
#include "stmpe811qtr.h"
#include <stm32f4xx.h>

void delay(__IO uint32_t nCount);
void LCD_DrawPoint(void) ;
