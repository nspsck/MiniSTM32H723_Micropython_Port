#define MICROPY_HW_BOARD_NAME               "WeActStudio MiniSTM32H723"
#define MICROPY_HW_MCU_NAME                 "STM32H723VGT6"
#define MICROPY_PY_SYS_PLATFORM             "MiniSTM32H723"
#define MICROPY_HW_FLASH_FS_LABEL           "MiniSTM32H723"

#define MICROPY_HW_ENABLE_RTC               (1)
#define MICROPY_HW_ENABLE_RNG               (1) // RNG needs proper configuration
#define MICROPY_HW_ENABLE_ADC               (1)
#define MICROPY_HW_ENABLE_DAC               (1)
#define MICROPY_HW_ENABLE_TIMER             (1)
#define MICROPY_HW_ENABLE_SERVO             (1)
#define MICROPY_HW_ENABLE_USB               (1)
#define MICROPY_HW_ENABLE_SDCARD            (1)
#define MICROPY_HW_ENABLE_MMCARD            (0)
#define MICROPY_HW_HAS_SWITCH               (1)
#define MICROPY_HW_HAS_FLASH                (1)
#define MICROPY_HW_HAS_LCD                  (0)
#define MICROPY_FATFS_EXFAT                 (1)

// Flash storage config
#define MICROPY_HW_SPIFLASH_ENABLE_CACHE            (1)
#define MICROPY_HW_ENABLE_INTERNAL_FLASH_STORAGE    (0)

#if !MICROPY_HW_ENABLE_INTERNAL_FLASH_STORAGE
// QSPI flash for storage
#define MICROPY_HW_OSPI_PRESCALER           (2) // 100MHz
#define MICROPY_HW_OSPIFLASH_SIZE_BITS_LOG2 (26)
#define MICROPY_HW_SPIFLASH_SIZE_BITS       (64 * 1024 * 1024)
#define MICROPY_HW_OSPIFLASH_CS             (pin_B6)
#define MICROPY_HW_OSPIFLASH_SCK            (pin_B2)
#define MICROPY_HW_OSPIFLASH_IO0            (pin_D11)
#define MICROPY_HW_OSPIFLASH_IO1            (pin_D12)
#define MICROPY_HW_OSPIFLASH_IO2            (pin_E2)
#define MICROPY_HW_OSPIFLASH_IO3            (pin_D13)

// SPI flash #1, block device config
extern const struct _mp_spiflash_config_t spiflash_config;
extern struct _spi_bdev_t spi_bdev;
#define MICROPY_HW_BDEV_SPIFLASH            (&spi_bdev)
#define MICROPY_HW_BDEV_SPIFLASH_CONFIG     (&spiflash_config)
#define MICROPY_HW_BDEV_SPIFLASH_SIZE_BYTES (MICROPY_HW_SPIFLASH_SIZE_BITS / 8)
#define MICROPY_HW_BDEV_SPIFLASH_EXTENDED   (&spi_bdev)
#endif

#define MICROPY_BOARD_EARLY_INIT            WEACT_H723ZG_board_early_init
void WEACT_H723ZG_board_early_init(void);

//PLL1 550MHz
#define MICROPY_HW_CLK_PLLM             (5)
#define MICROPY_HW_CLK_PLLN             (110)
#define MICROPY_HW_CLK_PLLP             (1)
#define MICROPY_HW_CLK_PLLQ             (4)
#define MICROPY_HW_CLK_PLLR             (2)
#define MICROPY_HW_CLK_PLLVCI           (RCC_PLL1VCIRANGE_2)
#define MICROPY_HW_CLK_PLLVCO           (RCC_PLL1VCOWIDE)
#define MICROPY_HW_CLK_PLLFRAC          (0)

// PLL2 200MHz for FMC and OSPI.
#define MICROPY_HW_CLK_PLL2M            (5)
#define MICROPY_HW_CLK_PLL2N            (80)
#define MICROPY_HW_CLK_PLL2P            (2)
#define MICROPY_HW_CLK_PLL2Q            (2)
#define MICROPY_HW_CLK_PLL2R            (2)
#define MICROPY_HW_CLK_PLL2VCI          (RCC_PLL2VCIRANGE_2)
#define MICROPY_HW_CLK_PLL2VCO          (RCC_PLL2VCOWIDE)
#define MICROPY_HW_CLK_PLL2FRAC         (0)

// PLL3 120MHz
#define MICROPY_HW_CLK_PLL3M            (5)
#define MICROPY_HW_CLK_PLL3N            (96)
#define MICROPY_HW_CLK_PLL3P            (2)
#define MICROPY_HW_CLK_PLL3Q            (5)
#define MICROPY_HW_CLK_PLL3R            (2)
#define MICROPY_HW_CLK_PLL3VCI          (RCC_PLL3VCIRANGE_2)
#define MICROPY_HW_CLK_PLL3VCO          (RCC_PLL3VCOWIDE)
#define MICROPY_HW_CLK_PLL3FRAC         (0)

// Bus clock divider values
#define MICROPY_HW_CLK_AHB_DIV          (RCC_HCLK_DIV2)
#define MICROPY_HW_CLK_APB1_DIV         (RCC_APB1_DIV2)
#define MICROPY_HW_CLK_APB2_DIV         (RCC_APB2_DIV2)
#define MICROPY_HW_CLK_APB3_DIV         (RCC_APB3_DIV2)
#define MICROPY_HW_CLK_APB4_DIV         (RCC_APB4_DIV2)

// Peripheral clock sources
#define MICROPY_HW_RCC_HSI48_STATE      (RCC_HSI48_ON)
#define MICROPY_HW_RCC_USB_CLKSOURCE    (RCC_USBCLKSOURCE_HSI48)
#define MICROPY_HW_RCC_RNG_CLKSOURCE    (RCC_RNGCLKSOURCE_HSI48)
#define MICROPY_HW_RCC_ADC_CLKSOURCE    (RCC_ADCCLKSOURCE_PLL3)
#define MICROPY_HW_RCC_SDMMC_CLKSOURCE  (RCC_SDMMCCLKSOURCE_PLL)
#define MICROPY_HW_RCC_FDCAN_CLKSOURCE  (RCC_FDCANCLKSOURCE_PLL)
// #define MICROPY_HW_RCC_SPI123_CLKSOURCE (RCC_SPI123CLKSOURCE_PLL3)
// #define MICROPY_HW_RCC_I2C123_CLKSOURCE (RCC_I2C123CLKSOURCE_D2PCLK1)
#define MICROPY_HW_RCC_OSPI_CLKSOURCE   (RCC_OSPICLKSOURCE_PLL2)

// 4 wait states
#define MICROPY_HW_FLASH_LATENCY            FLASH_LATENCY_2

// The board has an external 32kHz crystal attached
#define MICROPY_HW_RTC_USE_LSE              (1)

// USART
#define MICROPY_HW_UART1_TX                 (pin_B14) // valid: PA9, PB6, PB14
#define MICROPY_HW_UART1_RX                 (pin_B15) // valid: PA10, PB7, PB15
#define MICROPY_HW_UART2_TX                 (pin_A2) // valid: PA2 (boot), PD5
#define MICROPY_HW_UART2_RX                 (pin_A3) // valid: PA3 (boot), PD6
#define MICROPY_HW_UART3_TX                 (pin_D8) // valid: PB10, PC10, PD8
#define MICROPY_HW_UART3_RX                 (pin_D9) // valid: PB11, PC11, PD9
// Disabled because: interfered with camera.
// #define MICROPY_HW_UART6_TX                 (pin_C6) // valid: PC6
// #define MICROPY_HW_UART6_RX                 (pin_C7) // valid: PC7
// UART
#define MICROPY_HW_UART4_TX                 (pin_A0) // valid: PA0, PA12, PB9, PC10, PD1 
#define MICROPY_HW_UART4_RX                 (pin_A1) // valid: PA1, PA11, PB8, PC11, PD0
// Disabled because: To make place for FDCAN2.
// #define MICROPY_HW_UART5_TX                 (pin_B13) // valid: PB6, PB13, PC12
// #define MICROPY_HW_UART5_RX                 (pin_B12) // valid: PB5, PB12, PD2
#define MICROPY_HW_UART7_TX                 (pin_E8) // valid: PA15, PE8
#define MICROPY_HW_UART7_RX                 (pin_E7) // valid: PA8, PE7
// Disabled because: interfered with camera.
// #define MICROPY_HW_UART8_TX                 (pin_E1) // valid: PE1
// #define MICROPY_HW_UART8_RX                 (pin_E0) // valid: PE0
#define MICROPY_HW_UART9_TX                 (pin_D15) // valid: PD15
#define MICROPY_HW_UART9_RX                 (pin_D14) // valid: PD14

#define MICROPY_HW_UART_REPL                PYB_UART_3
#define MICROPY_HW_UART_REPL_BAUD           115200

// I2C buses
#define MICROPY_HW_I2C1_SCL                 (pin_B8) // valid: PB6, PB8
#define MICROPY_HW_I2C1_SDA                 (pin_B9) // valid: PB7, PB9
#define MICROPY_HW_I2C2_SCL                 (pin_B10) // valid: PB10
#define MICROPY_HW_I2C2_SDA                 (pin_B11) // valid: PB11
// Disabled because: PC9 used by SDMMC1.
// #define MICROPY_HW_I2C3_SCL                 (pin_A8) // valid: PA8 (boot)
// #define MICROPY_HW_I2C3_SDA                 (pin_C9) // valid: PC9 (boot)
// Disabled because: PD12, PD13, PB6 is taken by OSPIFLASH and PB8 interfered with I2C1 and the camera.
// #define MICROPY_HW_I2C4_SCL                 (pin_D12) // valid: (PB6, PB8,) PD12
// #define MICROPY_HW_I2C4_SDA                 (pin_D13) // valid: (PB7, PB9,) PD13
// Disabled because: PC9, PC10, PC11 used by SDMMC1.
// #define MICROPY_HW_I2C5_SCL                 (pin_C11) // valid: (PA8,) PC11
// #define MICROPY_HW_I2C5_SDA                 (pin_C10) // valid: (PC9) PC10

// SPI buses
// "Audio class" SPI.
#define MICROPY_HW_SPI1_NAME                "SPIFLASH"
// #define MICROPY_HW_SPI1_NSS                 (SPI_NSS_SOFT) // valid: PA4 (boot), PA15
#define MICROPY_HW_SPI1_SCK                 (pin_B3) // valid: PA5 (boot), PB3
#define MICROPY_HW_SPI1_MISO                (pin_B4) // valid: PA6 (boot), PB4
#define MICROPY_HW_SPI1_MOSI                (pin_D7) // valid: PA7 (boot), PB5, PD7
#define MICROPY_HW_SPI2_NAME                "SPI2"
#define MICROPY_HW_SPI2_NSS                 (pin_A11) // valid: PA11, PB12, PB4
#define MICROPY_HW_SPI2_SCK                 (pin_A9) // valid: PA9, PA12, PB10, PB13, PD3
#define MICROPY_HW_SPI2_MISO                (pin_C2) // valid: PB14, PC2
#define MICROPY_HW_SPI2_MOSI                (pin_C3) // valid: PB15, PC1, PC3
// Disabled because: PB4 is taken for SPIFLASH, PC11 is taken by SDMMC1. 
// #define MICROPY_HW_SPI3_NAME                "SPI3"
// #define MICROPY_HW_SPI3_NSS                 (pin_A15) // valid: PA4, PA15 (boot)
// #define MICROPY_HW_SPI3_SCK                 (pin_C10) // valid: PC10 (boot), PB3
// #define MICROPY_HW_SPI3_MISO                (pin_C11) // valid: PC11, PB4
// #define MICROPY_HW_SPI3_MOSI                (pin_C12) // valid: PB2, PB5, PC12, PD6
// Disabled because: PA6 interfered with the camera and PB4 is taken for SPIFLASH
// #define MICROPY_HW_SPI6_NAME                "SPI6"
// #define MICROPY_HW_SPI6_NSS                 (pin_A0) // valid: PA0, PA4, PA15 
// #define MICROPY_HW_SPI6_SCK                 (pin_A5) // valid: PA5, PB3, PC12
// #define MICROPY_HW_SPI6_MISO                (pin_A6) // valid: PA6, PB4
// #define MICROPY_HW_SPI6_MOSI                (pin_A7) // valid: PA7, PB5
// "Normal" SPI.
#define MICROPY_HW_SPI4_NAME                "SPILCD"
#define MICROPY_HW_SPI4_NSS                 (pin_E11) // valid: PE4, PE11
#define MICROPY_HW_SPI4_SCK                 (pin_E12) // valid: PE2, PE12
#define MICROPY_HW_SPI4_MISO                (pin_E13) // valid: PE5, PE13
#define MICROPY_HW_SPI4_MOSI                (pin_E14) // valid: PE6, PE14
// Disabled because: PFx not available for STM32H7xx[V]xT6 [V]series.
// #define MICROPY_HW_SPI5_NAME                "SPI5"
// #define MICROPY_HW_SPI5_NSS                 (pin_B12) // valid: PF6
// #define MICROPY_HW_SPI5_SCK                 (pin_B13) // valid: PF7
// #define MICROPY_HW_SPI5_MISO                (pin_B14) // valid: PF8
// #define MICROPY_HW_SPI5_MOSI                (pin_B15) // valid: PF9, pF11

// USRSW is pulled low. Pressing the button makes the input go high.
#define MICROPY_HW_USRSW_PIN                (pin_C13)
#define MICROPY_HW_USRSW_PULL               (GPIO_NOPULL)
#define MICROPY_HW_USRSW_EXTI_MODE          (GPIO_MODE_IT_FALLING)
#define MICROPY_HW_USRSW_PRESSED            (1)

// LEDs
#define MICROPY_HW_LED1                     (pin_E3)    // blue
#define MICROPY_HW_LED_ON(pin)              (mp_hal_pin_high(pin))
#define MICROPY_HW_LED_OFF(pin)             (mp_hal_pin_low(pin))

// USB config
#define MICROPY_HW_USB_FS                   (0)
#define MICROPY_HW_USB_HS                   (1)
#define MICROPY_HW_USB_HS_IN_FS             (1)
#define MICROPY_HW_USB_MAIN_DEV             (USB_PHY_HS_ID)

// FDCAN bus
// FDCAN1 supports TT-FDCAN (time triggered CAN).
#define MICROPY_HW_CAN1_NAME                "FDCAN1"
#define MICROPY_HW_CAN1_TX                  (pin_D1) // valid: PA12, PD1, PB9
#define MICROPY_HW_CAN1_RX                  (pin_D0) // valid: PA11, PD0, PB8
// FDCAN2 and FDCAN3 does not support TT-FDCAN.
#define MICROPY_HW_CAN2_NAME                "FDCAN2"
#define MICROPY_HW_CAN2_TX                  (pin_B13) // valid: PB6, PB13
#define MICROPY_HW_CAN2_RX                  (pin_B12) // valid: PB5, PB12
// Disabled because: PD12, PD13 is taken by OSPIFLASH
// #define MICROPY_HW_CAN3_NAME                "FDCAN3"
// #define MICROPY_HW_CAN3_TX                  (pin_D13) // valid: PD13
// #define MICROPY_HW_CAN3_RX                  (pin_D12) // valid: PD12

// SD card detect switch
#define MICROPY_HW_SDCARD_SDMMC             (1)
#define MICROPY_HW_SDMMC1_CMD               (pin_D2)
#define MICROPY_HW_SDMMC1_D0                (pin_C8)
#define MICROPY_HW_SDMMC1_D1                (pin_C9)
#define MICROPY_HW_SDMMC1_D2                (pin_C10)
#define MICROPY_HW_SDMMC1_D3                (pin_C11)
#define MICROPY_HW_SDCARD_DETECT_PIN        (pin_D4)
#define MICROPY_HW_SDCARD_DETECT_PULL       (GPIO_PULLUP)
#define MICROPY_HW_SDCARD_DETECT_PRESENT    (GPIO_PIN_SET)
#define MICROPY_HW_SDCARD_MOUNT_AT_BOOT     (0)

// This is used to check if the camera interface has been interfered.
// DCMI_D0 -> PC6                           pin_C6
// DCMI_D1 -> PC7                           pin_C7
// DCMI_D2 -> PE0                           pin_E0
// DCMI_D3 -> PE1                           pin_E1
// DCMI_D4 -> PE4                           pin_E4
// DCMI_D5 -> PD3                           pin_D3
// DCMI_D6 -> PE5                           pin_E5
// DCMI_D7 -> PE6                           pin_E6
// DCMI_VSYNC -> PB7                        pin_B7
// DCMI_HSYNC -> PA4                        pin_A4
// DCMI_PIXCLK -> PA6                       pin_A6
// RCC_MCO_1 -> PA8                         pin_A8
// I2C1_SCL -> PB8                          pin_B8
// I2C1_SDA -> PB9                          pin_B9

#define MICROPY_HW_USB_VID                      0x1209
#define MICROPY_HW_USB_PID                      0xabd1
#define MICROPY_HW_USB_PID_CDC_MSC              (MICROPY_HW_USB_PID)
#define MICROPY_HW_USB_PID_CDC_HID              (MICROPY_HW_USB_PID)
#define MICROPY_HW_USB_PID_CDC                  (MICROPY_HW_USB_PID)
#define MICROPY_HW_USB_PID_MSC                  (MICROPY_HW_USB_PID)
#define MICROPY_HW_USB_PID_CDC2_MSC             (MICROPY_HW_USB_PID)
#define MICROPY_HW_USB_PID_CDC2                 (MICROPY_HW_USB_PID)
#define MICROPY_HW_USB_PID_CDC3                 (MICROPY_HW_USB_PID)
#define MICROPY_HW_USB_PID_CDC3_MSC             (MICROPY_HW_USB_PID)
#define MICROPY_HW_USB_PID_CDC_MSC_HID          (MICROPY_HW_USB_PID)
#define MICROPY_HW_USB_PID_CDC2_MSC_HID         (MICROPY_HW_USB_PID)
#define MICROPY_HW_USB_PID_CDC3_MSC_HID         (MICROPY_HW_USB_PID)
#define MICROPY_HW_USB_LANGID_STRING            0x409
#define MICROPY_HW_USB_MANUFACTURER_STRING      "WeActStudio"
#define MICROPY_HW_USB_PRODUCT_FS_STRING        "MiniSTM32H723 Virtual Comm Port in FS Mode"
#define MICROPY_HW_USB_PRODUCT_HS_STRING        "MiniSTM32H723 Virtual Comm Port in HS Mode"
#define MICROPY_HW_USB_INTERFACE_FS_STRING      "MiniSTM32H723 Interface"
#define MICROPY_HW_USB_INTERFACE_HS_STRING      "MiniSTM32H723 Interface"
#define MICROPY_HW_USB_CONFIGURATION_FS_STRING  "MiniSTM32H723 Config"
#define MICROPY_HW_USB_CONFIGURATION_HS_STRING  "MiniSTM32H723 Config"
