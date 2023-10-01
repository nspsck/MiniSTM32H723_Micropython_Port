# MiniSTM32H723_Micropython_Port

This port is a WIP and needs some tweaks to the official Micropython repo in order to work.
- [Required Tweaks](#required-tweaks)

## Update 10.1.2023
Resolved some pin-layout issues. Disabled some interfaces that could interfere with each others. Which leaves 5 x UARTs, 2 x I2Cs, 3 x SPIs and one FDCAN for the user to use. Renamed forder name to keep a standard with my other ports.

## Update 09.28.2023
Now disabled SD Card mount on boot. You can now leave the `MICROPY_HW_ENABLE_SDCARD` option on and not paying the "trying to mount a SD Card"-boot-time-expense. If you want to mount the SD Card on boot, you can still do that through `boot.py`.

## Update 09.28.2023
What works now:
- USB Serial/Storage
- USB HID
- SD Card
- OSPI Flash
- ADC, RTC, TIMER, SERVO, SWITCH, LED should work, tho not fully tested.
- REPL via USB and UART3 (TX:D8, RX:D9)

Known issues:
- There is a weird issue... If you press the `NSRT` button, the firmware thinks that it is it's first boot, hence it takes too long to boot. But if you are not pressing that button, you are just fine at 99% of the time. And if you do not intend to use SD Card, please disable `MICROPY_HW_ENABLE_SDCARD` by set it's value to `(0)`. This will save you some time on boot and soft-reset.

## Update 09.27.2023
The port is working now:
- Works without OSPI-flash, as well as with OSPI-flash.
- Directly connection via USB-port.
- Direct access to `.py` files.

tho, still some weird issues:
- On first connection, the board boots fast, then on resets per reset button, it boots very slow, and the LED1 blinks. This is somehow `MICROPY_HW_ENABLE_RNG`related? Because when I disable it, the boards always takes a long time to boot and when I enabled it, the stated behavior is shown.
- Some peripherals may not work.

## Required Tweaks

Here are [some tweaks](https://github.com/micropython/micropython/issues/12517) that you have to do for the firmware to be built successfully.

And it required some changes to `ports/stm32/system_stm32.c`, please add the following to roughly [line 463](https://github.com/micropython/micropython/blob/dd58be19eef0be304e1b0530fe6e7408ab9b9b84/ports/stm32/system_stm32.c#L463).
```c
    #if defined(MICROPY_HW_RCC_OSPI_CLKSOURCE)
    PeriphClkInitStruct.PeriphClockSelection |= RCC_PERIPHCLK_OSPI;
    PeriphClkInitStruct.OspiClockSelection = MICROPY_HW_RCC_OSPI_CLKSOURCE;
    #endif
```
