
/*
 * STM32F4XX.h
 *
 *  Created on: Dec 27, 2020
 *      Author: 99003181
 */

#ifndef INC_STM32F4XX_H_
#define INC_STM32F4XX_H_
/* defining macros for various memory */
#include<stdint.h>
#define __vo volatile
#define FLASHADDR   0x08000000U
#define SRAM1ADDR   0x20000000U
#define SRAM2ADDR   0x2001C000U
#define ROMADDR     0x1FFF0000U
#define SRAMADDR    SRAM1ADDR

/* defining macros for buses */
#define AHB1_BASEADDR    0x40020000U
#define AHB2_BASEADDR    0x50000000U
#define APB1_BASEADDR    0x40000000U
#define APB2_BASEADDR    0x40010000U
#define PERI_BASEADDR    APB1_BASEADDR


/* defining macros for peripherals which is hanging on AHP1 bus */
#define GPIOA_BASEADDR  (AHB1_BASEADDR+(0x0000U))
#define GPIOB_BASEADDR  (AHB1_BASEADDR+(0x4000U))
#define GPIOC_BASEADDR  (AHB1_BASEADDR+(0x0800U))
#define GPIOD_BASEADDR  (AHB1_BASEADDR+(0x0C00U))
#define GPIOE_BASEADDR  (AHB1_BASEADDR+(0x1000U))
#define GPIOF_BASEADDR  (AHB1_BASEADDR+(0x1400U))
#define GPIOG_BASEADDR  (AHB1_BASEADDR+(0x1800U))
#define GPIOH_BASEADDR  (AHB1_BASEADDR+(0x1C00U))
#define GPIOI_BASEADDR  (AHB1_BASEADDR+(0x2000U))
#define RCC_BASEADDR    (AHB1_BASEADDR+(0x3800U))

/* peripheral hanging on APB1 and APB2 */
#define SPI1_BASEADDR    (APB2_BASEADDR+(0x3000U))
#define SPI2_BASEADDR    (APB1_BASEADDR+(0x3800U))
#define SPI3_BASEADDR    (APB1_BASEADDR+(0x3C00U))

#define I2C1_BASEADDR    (APB1_BASEADDR+(0x5400U))
#define I2C2_BASEADDR    (APB1_BASEADDR+(0x5800U))
#define I2C3_BASEADDR    (APB1_BASEADDR+(0x5C00U))

#define USART1_BASEADDR  (APB2_BASEADDR+(0x1000U))
#define USART2_BASEADDR  (APB2_BASEADDR+(0x4400U))
#define USART3_BASEADDR  (APB1_BASEADDR+(0x4800U))
#define UART4_BASEADDR   (APB1_BASEADDR+(0x4C00U))
#define UART5_BASEADDR   (APB1_BASEADDR+(0x5000U))
#define USART6_BASEADDR  (APB2_BASEADDR+(0x1400U))

/* GPIO peripheral register */
typedef struct
{
__vo uint32_t MODER;
__vo uint32_t OTYPER;
__vo uint32_t OSPEEDER;
__vo uint32_t PUPDR;
__vo uint32_t IDR;
__vo uint32_t ODR;
__vo uint32_t BSRRL;
__vo uint32_t BSRRH;
__vo uint32_t LCKR;
__vo uint32_t AFR[2]; //AFR[0]-Low register;AFR[1]-High register

}Reg_def_t;
/* GPIO peripheral section */

#define GPIOA (Reg_def_t*)GPIOA_BASEADDR
#define GPIOB (Reg_def_t*)GPIOB_BASEADDR
#define GPIOC (Reg_def_t*)GPIOC_BASEADDR
#define GPIOD (Reg_def_t*)GPIOD_BASEADDR
#define GPIOE (Reg_def_t*)GPIOE_BASEADDR
#define GPIOF (Reg_def_t*)GPIOF_BASEADDR
#define GPIOG (Reg_def_t*)GPIOG_BASEADDR
#define GPIOH (Reg_def_t*)GPIOH_BASEADDR
#define GPIOI (Reg_def_t*)GPIOI_BASEADDR

/* RCC Registers */
typedef struct
{
__vo uint32_t _CR;
__vo uint32_t _CPLLCFGR;
__vo uint32_t _CFGR;
__vo uint32_t _CIR;
__vo uint32_t _AHB1RSTR;
__vo uint32_t _AHB2RSTR;
__vo uint32_t _AHB3RSTR;
     uint32_t _RESERVED0;
__vo uint32_t _APB1RSTR;
__vo uint32_t _APB2RSTR;
    uint32_t _RESERVED1[2];
__vo uint32_t _AHB1ENR;
__vo uint32_t _AHB2ENR;
__vo uint32_t _AHB3ENR;
    uint32_t _RESERVED2;
__vo uint32_t _APB1ENR;
__vo uint32_t _APB2ER;
     uint32_t _RESERVED3[2];
__vo uint32_t _AHB1PENR;
__vo uint32_t _AHB2LPENR;
__vo uint32_t _HB3LPENR;
    uint32_t _RESERVED4;
__vo uint32_t _APB1LPENR;
__vo uint32_t _APB2LPENR;
    uint32_t _RESERVED5[2];
__vo uint32_t _BDCR;
__vo uint32_t _CSR;
     uint32_t _RESERVED6[2];
__vo uint32_t _SSCGR;
__vo uint32_t _PLLI2SCFGR;
__vo uint32_t _PLLSAICFGR;
__vo uint32_t _DCKCFGR;

} RCC_Reg_def_t;
#define RCC  ((RCC_Reg_def_t*)RCC_BASEADDR)

/* GPIO Clock enable */
#define GPIOA_PCLOCK_EN()   RCC->_AHB1ENR |= 1<<0
#define GPIOB_PCLOCK_EN()   RCC->_AHB1ENR |= 1<<1
#define GPIOC_PCLOCK_EN()   RCC->_AHB1ENR |= 1<<2
#define GPIOD_PCLOCK_EN()   RCC->_AHB1ENR |= 1<<3
#define GPIOE_PCLOCK_EN()   RCC->_AHB1ENR |= 1<<4
#define GPIOF_PCLOCK_EN()   RCC->_AHB1ENR |= 1<<5
#define GPIOG_PCLOCK_EN()   RCC->_AHB1ENR |= 1<<6
#define GPIOH_PCLOCK_EN()   RCC->_AHB1ENR |= 1<<7
#define GPIOI_PCLOCK_EN()   RCC->_AHB1ENR |= 1<<8

/* macro definition */
#define ENABLE  1
#define DISABLE 0
#define GPIO_PIN_SET  ENABLE
#define GPIO_PIN_RESSET  DISABLE


/*  GPIO peripheral clock disable macros */

#define GPIOA_PCLOCK_DI() do {(RCC->_AHB1RSTR |= 1<<0);(RCC->_AHB1RSTR |= ~(1<<0));}while(0)
#define GPIOB_PCLOCK_DI() do {(RCC->_AHB1RSTR |= 1<<0);(RCC->_AHB1RSTR |= ~(1<<1));}while(0)
#define GPIOC_PCLOCK_DI() do {(RCC->_AHB1RSTR |= 1<<0);(RCC->_AHB1RSTR |= ~(1<<2));}while(0)
#define GPIOD_PCLOCK_DI() do {(RCC->_AHB1RSTR |= 1<<0);(RCC->_AHB1RSTR |= ~(1<<3));}while(0)
#define GPIOE_PCLOCK_DI() do {(RCC->_AHB1RSTR |= 1<<0);(RCC->_AHB1RSTR |= ~(1<<4));}while(0)
#define GPIOF_PCLOCK_DI() do {(RCC->_AHB1RSTR |= 1<<0);(RCC->_AHB1RSTR |= ~(1<<5));}while(0)
#define GPIOG_PCLOCK_DI() do {(RCC->_AHB1RSTR |= 1<<0);(RCC->_AHB1RSTR |= ~(1<<6));}while(0)
#define GPIOH_PCLOCK_DI() do {(RCC->_AHB1RSTR |= 1<<0);(RCC->_AHB1RSTR |= ~(1<<7));}while(0)
#define GPIOI_PCLOCK_DI() do {(RCC->_AHB1RSTR |= 1<<0);(RCC->_AHB1RSTR |= ~(1<<8));}while(0)

#include "STM32FXX_GPIO_DRIVER.h"











#endif /* INC_STM32F4XX_H_ */
