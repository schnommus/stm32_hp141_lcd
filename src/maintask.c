#include "GUI.h"
#include <math.h>
#include <stdlib.h>
#include "stm32f7xx_hal.h"

short points[400];

long frameCounter = 0;
short fps = 0;
short up = 0;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    fps = frameCounter;
    frameCounter = 0;
    ++up;
}

void MainTask(void) {

    while(1) {

        for( int j = 0; j != 400; ++j ) {
            points[j] = rand()%200;
        }

        GUI_MULTIBUF_Begin();
        GUI_Clear();
        GUI_SetFont(&GUI_Font20_1);
        char buf[32];
        snprintf(buf, 32, "%d FPS. %dS UP", fps, up);
        GUI_DispStringAt( buf, 10, 10 );
        GUI_DrawGraph( points, 400, 40, 40 );
        //GUI_DispStringAt("Hello world!", (LCD_GetXSize()-100)/2, (LCD_GetYSize()-20)/2+50*sin(((float)i)/100.0f));
        GUI_MULTIBUF_End();
        ++frameCounter;
    }
}
