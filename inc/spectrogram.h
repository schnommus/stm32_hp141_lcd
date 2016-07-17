#ifndef SPECTROGRAM_H
#define SPECTROGRAM_H

typedef struct _spectrogram {
    short pos_x;
    short pos_y;

    short size_x;
    short size_y;

    short graticules_nx;
    short graticules_ny;

    float graticule_start_y;
    float graticule_step_y;

    short npoints;

    short *data;
} spectrogram_t;

spectrogram_t *spectrogram_default();

void spectrogram_init_data(spectrogram_t *s);

void spectrogram_draw(spectrogram_t* s);

void spectrogram_fake_data(spectrogram_t* s);

#endif
