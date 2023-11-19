USE_MBOOT ?= 0

# MCU settings
MCU_SERIES = h7
CMSIS_MCU = STM32H723xx
MICROPY_FLOAT_IMPL = double
AF_FILE = boards/stm32h723_af.csv

ifeq ($(USE_MBOOT),1)
# When using Mboot everything goes after the bootloader
LD_FILES = boards/WEACTH723VG/stm32h723.ld boards/common_bl.ld
TEXT0_ADDR = 0x08020000
else
# When not using Mboot everything goes at the start of flash
LD_FILES = boards/WEACTH723VG/stm32h723.ld boards/common_basic.ld
TEXT0_ADDR = 0x08000000
endif

# Provide different variants for the downloads page.
ifeq ($(BOARD_VARIANT),DP)
MICROPY_FLOAT_IMPL=double
endif

ifeq ($(BOARD_VARIANT),THREAD)
CFLAGS += -DMICROPY_PY_THREAD=1
endif

ifeq ($(BOARD_VARIANT),DP_THREAD)
MICROPY_FLOAT_IMPL=double
CFLAGS += -DMICROPY_PY_THREAD=1
endif

ifeq ($(BOARD_VARIANT),NETWORK)
MICROPY_PY_NETWORK_WIZNET5K=5200
endif

# MicroPython settings
MICROPY_PY_LWIP ?= 1
MICROPY_PY_SSL ?= 1
MICROPY_SSL_MBEDTLS ?= 1
MICROPY_VFS_LFS2 ?= 1

FROZEN_MANIFEST ?= $(BOARD_DIR)/manifest.py
