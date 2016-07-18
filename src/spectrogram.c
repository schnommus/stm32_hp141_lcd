
#include <math.h>
#include <stdlib.h>
#include "stm32f7xx_hal.h"
#include "GUI.h"
#include "spectrogram.h"


spectrogram_t *spectrogram_default() {
    spectrogram_t *s = malloc(sizeof(spectrogram_t));

    s->pos_x = 30;
    s->pos_y = 5;

    s->graticules_nx = 12;
    s->graticules_ny = 10;

    s->graticule_start_y = 0;
    s->graticule_step_y = -10;

    s->size_x = 360;
    s->size_y = 225;

    s->npoints = s->size_x;

    spectrogram_init_data(s);

    return s;
}

void spectrogram_init_data(spectrogram_t *s) {
    s->data = calloc(s->npoints * sizeof(short),0);
}

void spectrogram_draw(spectrogram_t* s) {

    GUI_SetColor(GUI_DARKGRAY);

    for( int i = 0; i != s->graticules_nx; ++i ) {
        GUI_DrawVLine(s->pos_x + i * s->size_x/s->graticules_nx, s->pos_y, s->pos_y+s->size_y);
        for( int k = 0; k != 5; ++k) {
            GUI_DrawVLine(s->pos_x + i * s->size_x/s->graticules_nx
                          + k * 0.2*s->size_x/s->graticules_nx,
                          s->pos_y+s->size_y/2-3,
                          s->pos_y+s->size_y/2+3);
        }
    }

    for( int i = 0; i != s->graticules_ny; ++i ) {
        GUI_DrawHLine(s->pos_y + i * s->size_y/s->graticules_ny, s->pos_x, s->pos_x+s->size_x);
        for( int k = 0; k != 5; ++k) {
            GUI_DrawHLine(s->pos_y + i * s->size_y/s->graticules_ny
                          + k * 0.2*s->size_y/s->graticules_ny,
                          s->pos_x+s->size_x/2-3,
                          s->pos_x+s->size_x/2+3);
        }
    }

    GUI_SetColor(GUI_WHITE);

    GUI_DrawRoundedFrame(s->pos_x, s->pos_y, s->size_x+s->pos_x, s->size_y+s->pos_y, 3, 2);

    GUI_SetColor(GUI_YELLOW);

    GUI_DrawGraph( s->data, s->npoints, s->pos_x, s->pos_y );

    GUI_SetColor(GUI_WHITE);
    GUI_SetFont(&GUI_Font8_ASCII);

    char buf[16];
    for( int i = 0; i != s->graticules_ny+1; ++i ) {
        snprintf(buf, 32, "%d",(int)(s->graticule_start_y + i*s->graticule_step_y));
        GUI_SetTextAlign( GUI_TA_RIGHT | GUI_TA_VCENTER);
        GUI_DispStringAt( buf, -3 + s->pos_x, s->pos_y + i * s->size_y/s->graticules_ny );
    }
}

void spectrogram_fake_data(spectrogram_t* s) {
    static float inc = 0;
    inc += 0.05;
    for( int j = 0; j != s->npoints; ++j ) {
        s->data[j] = s->size_y -
                    fmax(rand()%30+10,
                         rand()%2+s->npoints/2-20 - (j-s->npoints/2+50*sin(inc))*(j-s->npoints/2+50*sin(inc))
                         );
    }
}
