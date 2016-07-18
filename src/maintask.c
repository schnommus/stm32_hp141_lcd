#include "GUI.h"
#include <math.h>
#include <stdlib.h>
#include "stm32f7xx_hal.h"
#include "spectrogram.h"
#include "BUTTON.h"
#include "WM.h"

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

    spectrogram_t *s = spectrogram_default();

    while(1) {

        spectrogram_fake_data(s);

        GUI_MULTIBUF_Begin();
        GUI_Clear();

        GUI_SetFont(&GUI_Font8_ASCII);
        char buf[32];
        snprintf(buf, 32, "%dF/%dU", fps, up);
        GUI_SetTextAlign( GUI_TA_RIGHT | GUI_TA_BOTTOM);
        GUI_DispStringAt( buf, LCD_GetXSize(), LCD_GetYSize());

        spectrogram_draw(s);

        GUI_SetFont(&GUI_Font8x15B_ASCII);
        GUI_SetTextAlign( GUI_TA_LEFT | GUI_TA_BOTTOM);
        GUI_DispStringAt( "START: 10.00 MHz", 10, LCD_GetYSize()-16);
        GUI_DispStringAt( "STOP:  2.000 GHz", 10, LCD_GetYSize());
        GUI_DispStringAt( "RBW: 300.0 KHz", 158, LCD_GetYSize()-16);
        GUI_DispStringAt( "ST:  10.00 mS", 158, LCD_GetYSize());
        GUI_DispStringAt( "MIX. MODE: 1+", 290, LCD_GetYSize()-16);
        GUI_DispStringAt( "0.0 - 2.0 GHz", 290, LCD_GetYSize());

        GUI_MULTIBUF_End();
        ++frameCounter;
    }
}
