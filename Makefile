EXECUTABLE=out.elf
STM32_LIBS=/opt/STM32Cube_FW_F4_V1.12.0

CC=arm-none-eabi-gcc
#LD=arm-none-eabi-ld 
LD=arm-none-eabi-gcc
AR=arm-none-eabi-ar
AS=arm-none-eabi-as
CP=arm-none-eabi-objcopy
OD=arm-none-eabi-objdump

DEFS = -DSTM32F429xx -DUSE_HAL_DRIVER -DUSE_STM32F429I_DISCO -DUSE_USB_OTG_HS -DUSE_EMBEDDED_PHY
MCU = cortex-m4
MCFLAGS = -mcpu=$(MCU) -mthumb -mlittle-endian -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb-interwork  

STM32_INCLUDES = -I$(STM32_LIBS)/Utilities/STM32F4-Discovery \
	-I$(STM32_LIBS)/Drivers/BSP/STM32F429I-Discovery \
	-I$(STM32_LIBS)/Drivers/CMSIS/Include/ \
	-I$(STM32_LIBS)/Drivers/CMSIS/Device/ST/STM32F4xx/Include \
    -I$(STM32_LIBS)/Drivers/STM32F4xx_HAL_Driver/Inc \
	-I$(STM32_LIBS)/Middlewares/Third_Party/FatFs/src \
	-I$(STM32_LIBS)/Middlewares/ST/STM32_USB_Host_Library/Core/Inc \
	-I$(STM32_LIBS)/Middlewares/Third_Party/FatFs/src/drivers \
	-I$(STM32_LIBS)/Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Inc

OPTIMIZE       = -Os

CFLAGS	= $(MCFLAGS)  $(OPTIMIZE)  $(DEFS) -IInc -I./ -I./ $(STM32_INCLUDES)  -Wl,-T,Src/STM32F429ZITx_FLASH.ld
AFLAGS	= $(MCFLAGS)

SRC = ./Src/startup_stm32f429xx.s \
	  ./Src/stm32f4xx_it.c \
	  ./Src/ts_calibration.c \
	  ./Src/main.c \
	  ./Src/system_stm32f4xx.c \
	  ./Src/syscalls.c \
	  $(STM32_LIBS)/Drivers/BSP/STM32F429I-Discovery/stm32f429i_discovery_io.c \
	  $(STM32_LIBS)/Drivers/BSP/STM32F429I-Discovery/stm32f429i_discovery.c \
	  $(STM32_LIBS)/Drivers/BSP/STM32F429I-Discovery/stm32f429i_discovery_lcd.c \
	  $(STM32_LIBS)/Drivers/BSP/STM32F429I-Discovery/stm32f429i_discovery_sdram.c \
	  $(STM32_LIBS)/Drivers/BSP/STM32F429I-Discovery/stm32f429i_discovery_ts.c \
	  $(STM32_LIBS)/Drivers/BSP/Components/ili9341/ili9341.c \
	  $(STM32_LIBS)/Drivers/BSP/Components/stmpe811/stmpe811.c \
	  $(STM32_LIBS)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_ltdc.c \
	  $(STM32_LIBS)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.c \
	  $(STM32_LIBS)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_spi.c \
	  $(STM32_LIBS)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pcd.c \
	  $(STM32_LIBS)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma2d.c \
	  $(STM32_LIBS)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c \
	  $(STM32_LIBS)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_fmc.c \
	  $(STM32_LIBS)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c \
	  $(STM32_LIBS)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c \
	  $(STM32_LIBS)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2c_ex.c \
	  $(STM32_LIBS)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2s.c \
	  $(STM32_LIBS)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.c \
	  $(STM32_LIBS)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_hcd.c \
	  $(STM32_LIBS)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_sdram.c \
	  $(STM32_LIBS)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c \
	  $(STM32_LIBS)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.c \
	  $(STM32_LIBS)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.c \
	  $(STM32_LIBS)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c \
	  $(STM32_LIBS)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c \
	  $(STM32_LIBS)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_usb.c \
	  $(STM32_LIBS)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2c.c \
	  $(STM32_LIBS)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c \

OBJDIR = .
OBJ = $(SRC:%.c=$(OBJDIR)/%.o)

all: $(EXECUTABLE)

$(EXECUTABLE): $(SRC)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f Startup.lst  $(TARGET)  $(EXECUTABLE) *.lst $(OBJ) $(AUTOGEN)  *.out *.map \
*.dmp
