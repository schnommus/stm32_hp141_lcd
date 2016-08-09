#ifndef ADF5355_H
#define ADF5355_H

typedef struct _adf5355_reg0 {
    uint32_t CONTROL    :  4;
    uint32_t INT        : 16;
    uint32_t PRESCALER  :  1;
    uint32_t AUTOCAL    :  1;
    uint32_t            : 10;
} adf5355_reg0_t;

typedef struct _adf5355_reg1 {
    uint32_t CONTROL    :  4;
    uint32_t FRAC1      : 24;
    uint32_t            :  4;
} adf5355_reg1_t;

typedef struct _adf5355_reg2 {
    uint32_t CONTROL    :  4;
    uint32_t MOD2       : 14;
    uint32_t FRAC2      : 14;
} adf5355_reg2_t;

typedef struct _adf5355_reg3 {
    uint32_t CONTROL    :  4;
    uint32_t PHASE      : 24;
    uint32_t PHASE_ADJ  :  1;
    uint32_t PHASE_SYNC :  1;
    uint32_t SD_LOAD_R  :  1;
    uint32_t            :  1;
} adf5355_reg3_t;

#endif
