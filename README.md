# MiniSTM32H723_Micropython_Port

This port is a WIP and needs [some tweaks](https://github.com/micropython/micropython/issues/12517) to the official Micropython repo in order to work.

This port uses `D8` and `D9` as `TX` and `RX` to host the REPL, you have to connect these pins to a usb-uart bridge to get to the REPL. The USB does not function right now.

## Update 09.27.2023
The port is working now:
- Works without OSPI-flash, as well as with OSPI-flash.
- Directly connection via USB-port.
- Direct access to `.py` files.

tho, still some weird issues:
- On first connection, the board boots fast, then on resets per reset button, it boots very slow, and the LED1 blinks.
- Some peripherals may not work.

And it required some changes to `ports/stm32/system_stm32.c`, please add the following to roughly [line 463](https://github.com/micropython/micropython/blob/dd58be19eef0be304e1b0530fe6e7408ab9b9b84/ports/stm32/system_stm32.c#L463).
```c
    #if defined(MICROPY_HW_RCC_OSPI_CLKSOURCE)
    PeriphClkInitStruct.PeriphClockSelection |= RCC_PERIPHCLK_OSPI;
    PeriphClkInitStruct.OspiClockSelection = MICROPY_HW_RCC_OSPI_CLKSOURCE;
    #endif
```
