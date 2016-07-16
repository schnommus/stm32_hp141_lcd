/*********************************************************************
*                SEGGER MICROCONTROLLER SYSTEME GmbH                 *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 1996 - 2004  SEGGER Microcontroller Systeme GmbH        *
*                                                                    *
*        Internet: www.segger.com    Support:  support@segger.com    *
*                                                                    *
**********************************************************************

***** emWin - Graphical user interface for embedded applications *****
emWin is protected by international copyright laws.   Knowledge of the
source code may not be used to write a similar product.  This file may
only be used in accordance with a license and should not be re-
distributed in any way. We appreciate your understanding and fairness.
----------------------------------------------------------------------
File        : BASIC_HelloWorld.c
Purpose     : Simple demo drawing "Hello world"
----------------------------------------------------------------------
*/

#include "GUI.h"
#include <math.h>
#include <stdlib.h>
#include "stm32f7xx_hal.h"

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       MainTask
*/

short points[8000];

long frameCounter = 0;
short fps = 0;
short up = 0;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    fps = frameCounter;
    frameCounter = 0;
    ++up;
}

void MainTask(void) {

  int j;
  for( j = 0; j != 8000; ++j ) {
    points[j] = rand()%200;
  }
  while(1) {
      GUI_MULTIBUF_Begin();
      GUI_Clear();
      GUI_SetFont(&GUI_Font20_1);
      char buf[32];
      snprintf(buf, 32, "%d FPS. %dS UP", fps, up);
      GUI_DispStringAt( buf, 10, 10 );
      GUI_DrawGraph( points+rand()%7600, 400, 40, 40 );
      //GUI_DispStringAt("Hello world!", (LCD_GetXSize()-100)/2, (LCD_GetYSize()-20)/2+50*sin(((float)i)/100.0f));
      GUI_MULTIBUF_End();
      ++frameCounter;
  }
}

/*************************** End of file ****************************/
