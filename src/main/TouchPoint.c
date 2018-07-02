#include "TouchPoint.h"

/**
  * @brief  Inserts a delay time.
  * @param  nCount: specifies the delay time length.
  * @retval None
  */
void delay(__IO uint32_t nCount)
{
  __IO uint32_t index = 0; 
  for(index = (100000 * nCount); index != 0; index--)
  {
  }
}

void LCD_DrawPoint(void)
{
  Point_Struct touch_point;
  
    TS_STATE *pstate = NULL;
    LCD_SetTextColor(Black);
  while(1)
  {
    do 
    {
      pstate = IOE_TS_GetState();
      delay(10); 
    } while(!pstate->TouchDetected);
    touch_point.x = pstate->X;
    touch_point.y = pstate->Y;
    /* If AD result is abnormal, then LCD show nothing */
    if ((touch_point.x > TOUCH_AD_VALUE_MAX) 
      || (touch_point.x < TOUCH_AD_VALUE_MIN)
      || (touch_point.y > TOUCH_AD_VALUE_MAX)
      || (touch_point.y < TOUCH_AD_VALUE_MIN))
    {
      continue;
    }
    /* Convert the voltage along vertical and horizontal to the coordinates */
    touch_point.x = ((int)(touch_point.x * adjust_Para.xScale - adjust_Para.xOffset));
    touch_point.y = ((int)(touch_point.y * adjust_Para.yScale - adjust_Para.yOffset));

    if (touch_point.x >= LCD_PIXEL_WIDTH) {
      touch_point.x = LCD_PIXEL_WIDTH -1;
    }
    if (touch_point.y >= LCD_PIXEL_HEIGHT) {
      touch_point.y = LCD_PIXEL_HEIGHT -1;
    }
    /*Judge whether the inut point is the 1st point*/ 
      LCD_DrawFullCircle(touch_point.x, touch_point.y, 8);
  }
}
