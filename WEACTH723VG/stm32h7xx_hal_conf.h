/* This file is part of the MicroPython project, http://micropython.org/
 * The MIT License (MIT)
 * Copyright (c) 2019 Damien P. George
 */
#ifndef MICROPY_INCLUDED_STM32H7XX_HAL_CONF_H
#define MICROPY_INCLUDED_STM32H7XX_HAL_CONF_H

#include "boards/stm32h7xx_hal_conf_base.h"

// Oscillator values in Hz
#ifndef HSE_VALUE
#define HSE_VALUE (25000000)
#endif
#ifndef LSE_VALUE
#define LSE_VALUE (32768)
#endif
#ifndef EXTERNAL_CLOCK_VALUE
#define EXTERNAL_CLOCK_VALUE (12288000)
#endif

// Oscillator timeouts in ms
#define HSE_STARTUP_TIMEOUT (5000)
#define LSE_STARTUP_TIMEOUT (5000)

#endif // MICROPY_INCLUDED_STM32H7XX_HAL_CONF_H
