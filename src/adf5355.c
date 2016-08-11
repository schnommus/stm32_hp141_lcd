#include "adf5355.h"

int adf5355_set_frequency_hz( double f ) {
    return 0;
}

int adf5355_init( double init_f, int init_on ) {
    return 0;
}

void adf5355_enable_rf_out() {
}

void adf5355_disable_rf_out() {
}

void adf5355_enable_rf_doubler() {
}

void adf5355_disable_rf_doubler() {
}

inline void adf5355_clock_low() {
}

inline void adf5355_clock_high() {
}

inline void adf5355_data_low() {
}

inline void adf5355_data_high() {
}

inline void adf5355_le_low() {
}

inline void adf5355_le_high() {
}

void adf5355_send_register( uint32_t reg ) {
    adf5355_le_low();
    // delay > 25ns
    for( uint32_t i = 1 << 31; i != 0; i >>= 1 ) {
        // delay > 25ns
        adf5355_clock_low();
        // delay > 25ns
        i & reg ? adf5355_data_high() : adf5355_data_low();
        // delay > 25ns
        adf5355_clock_high();
    }
    // delay > 25ns
    adf5355_le_high();
}
