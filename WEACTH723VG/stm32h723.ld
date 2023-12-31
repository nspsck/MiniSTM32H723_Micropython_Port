/*
    GNU linker script for STM32H723
*/

/* Specify the memory areas */
MEMORY
{
    FLASH (rx)      : ORIGIN = 0x08000000, LENGTH = 768K    /* sectors 0-5 */
    FLASH_APP  (rx) : ORIGIN = 0x08020000, LENGTH = 640K    /* sectors 1-5 */
    FLASH_FS (r)    : ORIGIN = 0x080c0000, LENGTH = 256K    /* sectors 6-7 */
    DTCM (xrw)      : ORIGIN = 0x20000000, LENGTH = 128K    /* Used for FS storage cache */
    RAM (xrw)       : ORIGIN = 0x24000000, LENGTH = 320K    /* 128K + 192K RAM which is shared between AXI SRAM and ITCM */
    RAM_D2 (xrw)    : ORIGIN = 0x30000000, LENGTH = 32K     /* Entire D2 Domain*/
    RAM_SRAM4 (xrw) : ORIGIN = 0x38000000, LENGTH = 16K     /* SRAM4 on D3*/
}

/* produce a link error if there is not this amount of RAM for these sections */
_minimum_stack_size = 2K;
_minimum_heap_size = 16K;

/* Define the stack.  The stack is full descending so begins just above last byte
   of RAM.  Note that EABI requires the stack to be 8-byte aligned for a call. */
_estack = ORIGIN(RAM) + LENGTH(RAM) - _estack_reserve;
_sstack = _estack - 16K; /* tunable */

/* RAM extents for the garbage collector */
_ram_start = ORIGIN(RAM);
_ram_end = ORIGIN(RAM) + LENGTH(RAM);
_heap_start = _ebss; /* heap starts just after statically allocated memory */
_heap_end = _sstack;

/* Location of filesystem RAM cache */
_micropy_hw_internal_flash_storage_ram_cache_start = ORIGIN(DTCM);
_micropy_hw_internal_flash_storage_ram_cache_end = ORIGIN(DTCM) + LENGTH(DTCM);

/* Location of filesystem flash storage */
_micropy_hw_internal_flash_storage_start = ORIGIN(FLASH_FS);
_micropy_hw_internal_flash_storage_end = ORIGIN(FLASH_FS) + LENGTH(FLASH_FS);

/* Define output sections */
SECTIONS
{
    .eth_buffers (NOLOAD) : {
        . = ABSOLUTE(0x38000000);
        *eth.o*(.bss.eth_dma)
    } >RAM_SRAM4
}
