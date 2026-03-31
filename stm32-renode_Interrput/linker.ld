OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)


MEMORY
{
  flash (rx)  : ORIGIN = 0x08000000, LENGTH = 0x100000
  ram   (rwx) : ORIGIN = 0x20000000, LENGTH = 0x20000
}

PROVIDE(_stack_top = ORIGIN(ram) + LENGTH(ram));
ENTRY(Reset_Handler)
SECTIONS
{
    .vectors :
    {
        . = ALIGN(4);
        _svector = .;
        KEEP(*(.vectors))
        KEEP(*(.reset_handler))
        . = ALIGN(4);
        _evector = .;
    } > flash

    .text :
    {
        . = ALIGN(4);
        _stext = .;
        *(.text .text.*)
        *(.rodata .rodata*)
        . = ALIGN(4);
        _etext = .;
    } > flash

    .data : 
    {
        . = ALIGN(4);
        _srelocate = .;
        *(.data .data.*)
        . = ALIGN(4);
        _erelocate = .;
    } > ram

    //_sidata = LOADADDR(.data);   /* ✅ moved here */

    .bss (NOLOAD) :
    {
        . = ALIGN(4);
        _sbss = .;
        *(.bss .bss.*)
        . = ALIGN(4);
        _ebss = .;
    } > ram

    . = ALIGN(4);
    _end = .;
}