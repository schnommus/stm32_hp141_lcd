#ifndef ADC_H
#define ADC_H

#include "stm32f7xx_hal.h"

int adc_init();
int adc_new_data_available();
void adc_refresh();

#endif
