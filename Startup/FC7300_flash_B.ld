/*
 * APP B: symbols execute from the common low OTA window after hardware swap,
 * while ELF load addresses program physical PFlash Bank1.
 */
ENTRY(Reset_Handler)

__vector_size = 0x0400;
HEAP_SIZE = 0x400;
STACK_SIZE = 0x400;
OTA_SLOT_SIZE = 0x00200000;
OTA_HEADER_OFFSET = 0x001FF000;
OTA_EXEC_BASE = 0x01000000;
OTA_LOAD_BASE = 0x01200000;
OTA_HEADER_ADDR = 0x011FF000;
OTA_HEADER_LOAD_ADDR = 0x013FF000;

MEMORY
{
  ITCM          (RW) : ORIGIN = 0x00000000, LENGTH = 0x00010000
  ITCM_1        (RW) : ORIGIN = 0x00010000, LENGTH = 0x00010000
  PFLASH_EXEC   (RW) : ORIGIN = 0x01000000, LENGTH = 0x00200000
  PFLASH_LOAD   (RW) : ORIGIN = 0x01200000, LENGTH = 0x00200000
  DFLASH        (RW) : ORIGIN = 0x04000000, LENGTH = 0x00040000
  NVR           (RW) : ORIGIN = 0x04400000, LENGTH = 0x00002000
  DTCM          (RW) : ORIGIN = 0x20000000, LENGTH = 0x0000F800
  DTCM_STACK    (RW) : ORIGIN = 0x2000F800, LENGTH = 0x00000800
  DTCM_1        (RW) : ORIGIN = 0x20020000, LENGTH = 0x00010000
  SRAM_0        (RW) : ORIGIN = 0x21000000, LENGTH = 0x00020000
  SRAM_1        (RW) : ORIGIN = 0x21020000, LENGTH = 0x00020000
  SRAM_2        (RW) : ORIGIN = 0x21040000, LENGTH = 0x00040000
}

SECTIONS
{
  .text :
  {
    . = ALIGN(1024);
    __interrupts_start__ = .;
    . = ALIGN(4);
    KEEP(*(.isr_vector))
    __interrupts_end__ = .;
    . = ALIGN(4);
    *(.text)
    *(.text*)
    *(.rodata)
    *(.rodata*)
    *(.init)
    *(.fini)
    *(.eh_frame)
    . = ALIGN(4);
  } > PFLASH_EXEC AT > PFLASH_LOAD

  .ARM.extab :
  {
    *(.ARM.extab* .gnu.linkonce.armextab.*)
  } > PFLASH_EXEC AT > PFLASH_LOAD

  __exidx_start = .;
  .ARM.exidx :
  {
    *(.ARM.exidx* .gnu.linkonce.armexidx.*)
  } > PFLASH_EXEC AT > PFLASH_LOAD
  __exidx_end = .;

  .data :
  {
    __data_start__ = .;
    *(.data*)

    . = ALIGN(4);
    PROVIDE_HIDDEN (__preinit_array_start = .);
    KEEP(*(.preinit_array))
    PROVIDE_HIDDEN (__preinit_array_end = .);

    . = ALIGN(4);
    PROVIDE_HIDDEN (__init_array_start = .);
    KEEP(*(SORT(.init_array.*)))
    KEEP(*(.init_array))
    PROVIDE_HIDDEN (__init_array_end = .);

    . = ALIGN(4);
    PROVIDE_HIDDEN (__fini_array_start = .);
    KEEP(*(SORT(.fini_array.*)))
    KEEP(*(.fini_array))
    PROVIDE_HIDDEN (__fini_array_end = .);

    . = ALIGN(4);
    __data_end__ = .;
  } > SRAM_0 AT > PFLASH_LOAD

  /*
   * The debugger/programmer uses the physical LMA. At runtime Bank1 is mapped
   * to the low window, so startup must copy .data from the equivalent low VMA.
   */
  __data_load_physical__ = LOADADDR(.data);
  __data_init_start__ = OTA_EXEC_BASE + (LOADADDR(.data) - OTA_LOAD_BASE);
  __flash_payload_end__ = __data_init_start__ + SIZEOF(.data);

  .ota_header OTA_HEADER_ADDR : AT (OTA_HEADER_LOAD_ADDR)
  {
    . = ALIGN(8);
    __ota_header_start__ = .;
    KEEP(*(.ota_header))
    . = ALIGN(8);
    __ota_header_end__ = .;
  } > PFLASH_EXEC

  .bss (NOLOAD) :
  {
    __bss_start__ = .;
    *(.bss*)
    __bss_end__ = .;
  } > SRAM_0

  .heap :
  {
    . = ALIGN(8);
    __HeapBegin = .;
    _end = .;
    end = _end;
    . += HEAP_SIZE;
    . = ALIGN(8);
    __HeapLimit = .;
  } > DTCM_STACK

  .stack_dummy :
  {
    . = ALIGN(8);
    __StackLimit = .;
    . += STACK_SIZE;
    . = ALIGN(8);
    __StackTop = .;
  } > DTCM_STACK

  .ARM.attributes 0 : { *(.ARM.attributes) }

  ASSERT(__StackLimit >= __HeapLimit, "region RAM overflowed with STACK")
  ASSERT(__flash_payload_end__ <= OTA_HEADER_ADDR, "PFlash payload overlaps OTA header sector")
  ASSERT(__ota_header_start__ == OTA_HEADER_ADDR, "OTA header VMA mismatch")
  ASSERT(LOADADDR(.ota_header) == OTA_HEADER_LOAD_ADDR, "OTA header LMA mismatch")
  ASSERT(__ota_header_end__ <= (OTA_HEADER_ADDR + 0x80), "OTA header exceeds reserved size")
}
