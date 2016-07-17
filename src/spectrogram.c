
#include <math.h>
#include <stdlib.h>
#include "stm32f7xx_hal.h"
#include "GUI.h"
#include "spectrogram.h"


spectrogram_t *spectrogram_default() {
    spectrogram_t *s = malloc(sizeof(spectrogram_t));

    s->pos_x = 10;
    s->pos_y = 40;

    s->graticules_nx = 12;
    s->graticules_ny = 10;

    s->graticule_start_y = 0;
    s->graticule_step_y = -10;

    s->size_x = 350;
    s->size_y = 200;

    s->npoints = s->size_x;

    spectrogram_init_data(s);

    return s;
}

void spectrogram_init_data(spectrogram_t *s) {
    s->data = calloc(s->npoints * sizeof(short),0);
}

void spectrogram_draw(spectrogram_t* s) {
    for( int i = 0; i != s->graticules_nx; ++i ) {
        GUI_DrawVLine(s->pos_x + i * s->size_x/s->graticules_nx, s->pos_y, s->pos_y+s->size_y);
    }
    for( int i = 0; i != s->graticules_ny; ++i ) {
        GUI_DrawHLine(s->pos_y + i * s->size_y/s->graticules_ny, s->pos_x, s->pos_x+s->size_x);
    }
    GUI_DrawRoundedFrame(s->pos_x, s->pos_y, s->size_x+s->pos_x, s->size_y+s->pos_y, 2, 2);
    GUI_DrawGraph( s->data, s->npoints, s->pos_x, s->pos_y );
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
