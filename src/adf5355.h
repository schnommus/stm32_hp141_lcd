#ifndef ADF5355_H
#define ADF5355_H

#include <stdint.h>

typedef struct _adf5355_reg0 {
    const
    uint32_t CONTROL    :  4;
    uint32_t INT        : 16;
    uint32_t PRESCALER  :  1;
    uint32_t AUTOCAL    :  1;
    uint32_t            : 10;
} adf5355_reg0_t;

typedef struct _adf5355_reg1 {
    const
    uint32_t CONTROL    :  4;
    uint32_t FRAC1      : 24;
    uint32_t            :  4;
} adf5355_reg1_t;

typedef struct _adf5355_reg2 {
    const
    uint32_t CONTROL    :  4;
    uint32_t MOD2       : 14;
    uint32_t FRAC2      : 14;
} adf5355_reg2_t;

typedef struct _adf5355_reg3 {
    const
    uint32_t CONTROL    :  4;
    uint32_t PHASE      : 24;
    uint32_t PHASE_ADJ  :  1;
    uint32_t PHASE_SYNC :  1;
    uint32_t SD_LOAD_R  :  1;
    uint32_t            :  1;
} adf5355_reg3_t;

typedef struct _adf5355_reg4 {
    const
    uint32_t CONTROL    :  4;
    uint32_t COUNTER_R  :  1;
    uint32_t CP_TRIS    :  1;
    uint32_t PD         :  1;
    uint32_t PD_POL     :  1;
    uint32_t MUX_LOGIC  :  1;
    uint32_t REF_MODE   :  1;
    uint32_t CURRENT    :  4;
    uint32_t DOUBLE_BUF :  1;
    uint32_t R_COUNTER  : 10;
    uint32_t RDIV2      :  1;
    uint32_t REF_DOUBLE :  1;
    uint32_t MUXOUT     :  3;
    uint32_t            :  2;
} adf5355_reg4_t;

typedef struct _adf5355_reg5 {
    const
    uint32_t CONTROL    :  4;
    uint32_t            : 28;
} adf5355_reg5_t;

typedef struct _adf5355_reg6 {
    const
    uint32_t CONTROL    :  4;
    uint32_t RF_POWER   :  2;
    uint32_t RF_OUT_A   :  1;
    uint32_t            :  3;
    uint32_t RF_OUT_B   :  1;
    uint32_t MTLD       :  1;
    uint32_t            :  1;
    uint32_t CPUMP_I    :  8;
    uint32_t RF_DIVIDER :  3;
    uint32_t FEEDBACK   :  1;
    uint32_t            :  4;
    uint32_t NEG_BLEED  :  1;
    uint32_t GATED_BLEED:  1;
    uint32_t            :  1;
} adf5355_reg6_t;

typedef struct _adf5355_reg7 {
    const
    uint32_t CONTROL    :  4;
    uint32_t LD_MODE    :  1;
    uint32_t FRAC_N_PREC:  2;
    uint32_t LOL_MODE   :  1;
    uint32_t LD_CYCLE_N :  2;
    uint32_t            : 15;
    uint32_t LE_SYNC    :  1;
    uint32_t            :  6;
} adf5355_reg7_t;

typedef struct _adf5355_reg8 {
    const
    uint32_t CONTROL    :  4;
    uint32_t            : 28;
} adf5355_reg8_t;

typedef struct _adf5355_reg9 {
    const
    uint32_t CONTROL    :  4;
    uint32_t SYNTH_L_TO :  5;
    uint32_t AUTOLEV_TO :  5;
    uint32_t TIMEOUT    : 10;
    uint32_t VCO_BANDDIV:  8;
} adf5355_reg9_t;

typedef struct _adf5355_reg10 {
    const
    uint32_t CONTROL    :  4;
    uint32_t ADC_ENABLE :  1;
    uint32_t ADC_CONV   :  1;
    uint32_t ADC_CLK_DIV:  8;
    uint32_t            : 18;
} adf5355_reg10_t;

typedef struct _adf5355_reg11 {
    const
    uint32_t CONTROL    :  4;
    uint32_t            : 28;
} adf5355_reg11_t;

typedef struct _adf5355_reg12 {
    const
    uint32_t CONTROL    :  4;
    uint32_t            : 12;
    uint32_t RESYNC_CLK : 16;
} adf5355_reg12_t;

typedef struct _adf5355_registers {
    adf5355_reg0_t REG0;
    adf5355_reg1_t REG1;
    adf5355_reg2_t REG2;
    adf5355_reg3_t REG3;
    adf5355_reg4_t REG4;
    adf5355_reg5_t REG5;
    adf5355_reg6_t REG6;
    adf5355_reg7_t REG7;
    adf5355_reg8_t REG8;
    adf5355_reg9_t REG9;
    adf5355_reg10_t REG10;
    adf5355_reg11_t REG11;
    adf5355_reg12_t REG12;
} adf5355_registers_t;

typedef struct _adf5355 {
    adf5355_registers_t *reg;
} adf5355_t;

#endif
