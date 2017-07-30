# HP141T LCD Upgrade

This firmware is designed to run on an STM32F746G Discovery board used to upgrade the CRT of an HP141T spectrum analyzer.

A demo video with hardware connections and an overview of this codebase can be found on my channel here: <http://youtube.com/c/vk2seb>

## Prerequisites

Code was developed on Arch Linux. More work may be required to get it to compile on other distros.

You will require:
- `arm-none-eabi-gcc`, `arm-none-eabi-gdb`
- the STM32 cube F7 software suite (I install this at `/opt/STM32Cube_FW_F7_V1.5.0`, you will have to modify `STM32_LIBS` in the makefile for different directories)
- A recent version of `openocd`

## Building the code

    $ make

Will generate `out.elf` (this can be modified by changing `EXECUTABLE` in the makefile)

## Flashing / debugging

In one terminal:

    $ make debug_server

This will start the `openocd` server enabling gdb to communicate with the STM32F7 board.

In another terminal:

    $ debug_gdb

This will load the `out.elf` you compiled, flash it to the board and break at `main`. Type `c` and hit enter to continue execution. Alternatively you can just disconnect the board and reconnect it.
