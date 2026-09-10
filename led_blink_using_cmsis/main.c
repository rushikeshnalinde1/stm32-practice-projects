# include"stm32f4xx.h"

void main(void){

	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;



	GPIOA->MODER &= ~(3U << (2*5));
	GPIOA->MODER |= (1U << (2*5));

	GPIOC->MODER &= ~(3U << (2*13));


	while(1){

		if((GPIOC->IDR&(1U<<13)) == 0){
			GPIOA->ODR |= (1U << 5);
		}
		else{
			GPIOA->ODR &= ~(1U << 5);
		}

	}
}
