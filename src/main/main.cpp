#include "project_config.h"
#include "TouchPoint.h"
// #include "LCD_Touch_Calibration.h"
// #error "Setup"
// Перед использованием не забудьте выбрать микроконтроллер - с помощью дефайнов вида STM32F407xx и STM32F40_41xxx - на весь проект
// И выбрать правильную частоту кварца, установив на весь проект дефайн HSE_VALUE=8000000 или HSE_VALUE=12000000
// И выбрать правильный startup-файл с расширением .s в группе mcu_support_package
//#define HSE_VALUE 8000000

int main(void)
{
  IOE_Config();

  /* Initialize the LCD */
  STM32f4_Discovery_LCD_Init();
	
  /* Clear the LCD */ 
  LCD_Clear(White);
	
  /* Set the LCD Text size */
  LCD_SetFont(&Font8x12);

  Lcd_Touch_Calibration();
  LCD_Clear(White);
    
    while(1);
}

//#ifdef  USE_FULL_ASSERT
///**
//  * @brief  Reports the name of the source file and the source line number
//  *         where the assert_param error has occurred.
//  * @param  file: pointer to the source file name
//  * @param  line: assert_param error line source number
//  * @retval None
//  */
//void assert_failed(uint8_t* file, uint32_t line)
//{ 
//  /* User can add his own implementation to report the file name and line number,
//     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
// 
//  /* Infinite loop */
//  while (1)
//  {
//  }
//}
//#endif
