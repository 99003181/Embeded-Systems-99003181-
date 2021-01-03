
/*
 * STM32FXX_GPIO_DRIVER.c
 *
 *  Created on: Dec 28, 2020
 *      Author: 99003181
 */
#include "STM32FXX_GPIO_DRIVER.h"

/* PERIPHERAL CLOCK SETUP */
void GPIO_periClockControl(Reg_def_t *pGPIOx,uint8_t EnorDi)
{
if(EnorDi == ENABLE)
{
if(pGPIOx == GPIOA)
{
GPIOA_PCLOCK_EN();
}
if(pGPIOx == GPIOB)
{
GPIOB_PCLOCK_EN();
}
if(pGPIOx == GPIOC)
{
GPIOC_PCLOCK_EN();
}
if(pGPIOx == GPIOD)
{
GPIOD_PCLOCK_EN();
}
if(pGPIOx == GPIOE)
{
GPIOE_PCLOCK_EN();
}
if(pGPIOx == GPIOF)
{
GPIOF_PCLOCK_EN();
}
if(pGPIOx == GPIOG)
{
GPIOG_PCLOCK_EN();
}
if(pGPIOx == GPIOI)
{
GPIOI_PCLOCK_EN();
}


}
else
{
if(pGPIOx == GPIOA)
{
GPIOA_PCLOCK_DI();
}
if(pGPIOx == GPIOB)
{
GPIOB_PCLOCK_DI();
}
if(pGPIOx == GPIOC)
{
GPIOC_PCLOCK_DI();
}
if(pGPIOx == GPIOD)
{
GPIOD_PCLOCK_DI();
}
if(pGPIOx == GPIOE)
{
GPIOE_PCLOCK_DI();
}
if(pGPIOx == GPIOF)
{
GPIOF_PCLOCK_DI();
}
if(pGPIOx == GPIOG)
{
GPIOG_PCLOCK_DI();
}
if(pGPIOx == GPIOI)
{
GPIOI_PCLOCK_DI();
}

}
}

/* INIT AND DEINIT */
void GPIO_Init(GPIO_handle_t *pGPIOhandle)
{
/*1. configuring the mode */
uint32_t temp=0;
if(pGPIOhandle->pin_config.GPIO_PinMode<=GPIO_Mode_Analog )//this is for non interrupt
{
temp = pGPIOhandle->pin_config.GPIO_PinMode<<(2*pGPIOhandle->pin_config.GPIO_PinNumber);
pGPIOhandle->pGPIOx->MODER |= temp;

}
/* configuring the speed */
temp=0;
temp = pGPIOhandle->pin_config.GPIO_PinSpeed<<(pGPIOhandle->pin_config.GPIO_PinNumber);
pGPIOhandle->pGPIOx->OSPEEDER |= temp;

/* configuring OTYPER */

temp=0;
temp = pGPIOhandle->pin_config.GPIO_PinOType<<(pGPIOhandle->pin_config.GPIO_PinNumber);
pGPIOhandle->pGPIOx->OTYPER &=~(0x1 <<pGPIOhandle->pin_config.GPIO_PinNumber);
pGPIOhandle->pGPIOx->OTYPER |= temp;
/* configuring PUPDR */
temp=0;
temp = pGPIOhandle->pin_config.GPIO_PinPuPdControl<<(pGPIOhandle->pin_config.GPIO_PinNumber);
pGPIOhandle->pGPIOx->PUPDR |= temp;


/* alternate function */
if(pGPIOhandle->pin_config.GPIO_PinMode == GPIO_Mode_ALT)
{
uint32_t temp4=0,temp5=0;
temp4=pGPIOhandle->pin_config.GPIO_PinAltFuction / 8;
temp5=pGPIOhandle->pin_config.GPIO_PinAltFuction % 8;
pGPIOhandle->pGPIOx->AFR[temp4]&=~(0xF << (4* temp5));
pGPIOhandle->pGPIOx->AFR[temp4] |= pGPIOhandle->pin_config.GPIO_PinAltFuction <<(4* temp5);
}
}
void GPIO_Deinit(Reg_def_t *pGPIOx)
{
if(pGPIOx == GPIOA)
{
GPIOA_PCLOCK_DI();
}
if(pGPIOx == GPIOB)
{
GPIOB_PCLOCK_DI();
}
if(pGPIOx == GPIOC)
{
GPIOC_PCLOCK_DI();
}
if(pGPIOx == GPIOD)
{
GPIOD_PCLOCK_DI();
}
if(pGPIOx == GPIOE)
{
GPIOE_PCLOCK_DI();
}
if(pGPIOx == GPIOF)
{
GPIOF_PCLOCK_DI();
}
if(pGPIOx == GPIOG)
{
GPIOG_PCLOCK_DI();
}
if(pGPIOx == GPIOI)
{
GPIOI_PCLOCK_DI();
}
}


/* read and write */
uint8_t GPIO_ReadFromInputPin(Reg_def_t *pGPIOx,uint8_t pinNumber)
{
uint8_t value;
value = (uint8_t) (pGPIOx->IDR>>pinNumber)*(0x00000001);
return value;

}
uint8_t GPIO_ReadFromInputPort(Reg_def_t *pGPIOx)
{
uint16_t value1;
value1 = (uint16_t)(pGPIOx->IDR);
return value1;

}

void GPIO_WriteToOutputPin(Reg_def_t *pGPIOx,uint8_t pinNumber,uint8_t Value)
{
if(Value==GPIO_PIN_SET)
{
pGPIOx->ODR |= (1 <<pinNumber);
}
else
{
pGPIOx->ODR &= ~ (1 <<pinNumber);
}
}
void GPIO_WriteToOutputPort(Reg_def_t *pGPIOx, uint16_t Value)
{
pGPIOx->ODR = Value;

}
void GPIO_ToggleOutputPin(Reg_def_t *pGPIOx,uint8_t pinNumber)
{
pGPIOx->ODR = pGPIOx->ODR ^(1 <<pinNumber);
