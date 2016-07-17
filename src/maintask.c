#include "GUI.h"
#include <math.h>
#include <stdlib.h>
#include "stm32f7xx_hal.h"
#include "spectrogram.h"

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

        GUI_SetFont(&GUI_Font20_1);
        char buf[32];
        snprintf(buf, 32, "%d FPS. %dS UP", fps, up);
        GUI_DispStringAt( buf, 10, 10 );

        spectrogram_draw(s);

        GUI_MULTIBUF_End();
        ++frameCounter;
    }
}
