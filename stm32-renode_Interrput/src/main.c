#include <stdint.h>
#include "drivers.h"
#include "stm32f407xx.h"

// int main(void) {
//   RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN_Msk;
//   GPIOD->MODER |= 0x1 << GPIO_MODER_MODER12_Pos;
//   GPIOD->ODR |= GPIO_ODR_OD12_Msk;
//   while (1)
//   {
//     // GPIOD->ODR ^= GPIO_ODR_OD12_Msk;
//     // for(int i = 0; i < 100000; i++){
//     //     for(int j = 0; j < 100; j++){
//     //     __NOP();
//     //   }
//     // }
//   };
//   return 0;
// }
void TIM2_IRQHandler(void)
{
    if (TIM2->SR & 1)
    {
        TIM2->SR &= ~(1 << 0);
        GPIOB->ODR ^= (1 << 0);
    }
}

int main(void)
{
    GPIO_Init();
    TIM2_Init();
    NVIC_Enable();

    while(1)
    {
        // CPU free! No delay loop
    }
}