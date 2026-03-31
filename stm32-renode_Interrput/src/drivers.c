#include <stdint.h>
#include "stm32f407xx.h"
#include "drivers.h"

/* Enable GPIOB (for LED on PB0) */
void GPIO_Init(void)
{
    RCC->AHB1ENR |= (1 << 1);        // Enable GPIOB clock
    GPIOB->MODER &= ~(3 << (0 * 2)); // Clear mode
    GPIOB->MODER |= (1 << (0 * 2));  // PB0 = output
}

/* Configure TIM2 */
void TIM2_Init(void)
{
    RCC->APB1ENR |= (1 << 0);   // Enable TIM2 clock

    TIM2->PSC = 16000 - 1;      // Prescaler (assuming 16 MHz clock → 1 kHz)
    TIM2->ARR = 1000 - 1;       // 1 second overflow

    TIM2->DIER |= (1 << 0);     // Enable update interrupt
    TIM2->CR1  |= (1 << 0);     // Start timer
}

/* Enable interrupt in NVIC */
void NVIC_Enable(void)
{
    *((volatile uint32_t*)0xE000E100) |= (1 << 28);  // Enable IRQ28 (TIM2)
}