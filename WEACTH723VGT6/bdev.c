#include "storage.h"
#include "octospi.h"

#if MICROPY_HW_SPIFLASH_ENABLE_CACHE
// Shared cache for first and second SPI block devices
STATIC mp_spiflash_cache_t spi_bdev_cache;
#endif

// First external SPI flash uses hardware QSPI interface
const mp_spiflash_config_t spiflash_config = {
    .bus_kind = MP_SPIFLASH_BUS_QSPI,
    .bus.u_qspi.data = NULL,
    .bus.u_qspi.proto = &octospi_proto,
    #if MICROPY_HW_SPIFLASH_ENABLE_CACHE
    .cache = &spi_bdev_cache,
    #endif
};

spi_bdev_t spi_bdev;