#include <stdint.h>

/* Linker symbols */
extern uint32_t _etext;
extern uint32_t _srelocate;
extern uint32_t _erelocate;
extern uint32_t _sbss;
extern uint32_t _ebss;
extern void _stack_top(void);

/* Main function */
extern int main(void);

/* Function declarations */
void Reset_Handler(void);
void Default_Handler(void);

/* Default handler (for unused interrupts) */
void Default_Handler(void)
{
    while (1);
}

/* Weak alias: if not defined elsewhere → use Default_Handler */
void TIM2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));

/* Vector table */
__attribute__((used, section(".vectors")))
void (*const vectors[])(void) = {
    [0 ... 100] = Default_Handler,   // Fill all entries safely

    [0] = &_stack_top,              // Initial Stack Pointer
    [1] = Reset_Handler,            // Reset Handler
    [2] = Default_Handler,          // NMI
    [3] = Default_Handler,          // HardFault

    [44] = TIM2_IRQHandler          // TIM2 Interrupt (IRQ28 → index 44)
};

/* Reset Handler */
__attribute__((used, section(".reset_handler")))
void Reset_Handler(void)
{
    uint32_t *pSrc = &_etext;
    uint32_t *pDest = &_srelocate;

    /* Copy .data section from FLASH to RAM */
    while (pDest < &_erelocate)
    {
        *pDest++ = *pSrc++;
    }

    /* Clear .bss section */
    for (pDest = &_sbss; pDest < &_ebss;)
    {
        *pDest++ = 0;
    }

    /* Call main */
    main();

    /* Infinite loop if main returns */
    while (1);
}