
/*
 * STM32FXX_GPIO_DRIVER.h
 *
 *  Created on: Dec 28, 2020
 *      Author: 99003179
 */

#ifndef INC_STM32FXX_GPIO_DRIVER_H_
#define INC_STM32FXX_GPIO_DRIVER_H_
#include "STM32F4XX.h"
//GPIO pin configuration
typedef struct {
uint8_t GPIO_PinNumber;
uint8_t GPIO_PinMode;
uint8_t GPIO_PinSpeed;
uint8_t GPIO_PinPuPdControl;
uint8_t GPIO_PinOType;
uint8_t GPIO_PinAltFuction;
}GPIO_PIN_CONFIG_t;

//GPIO pin numbers
#define GPIO_Pin_Number_0  0
#define GPIO_Pin_Number_1  1
#define GPIO_Pin_Number_2  2
#define GPIO_Pin_Number_3  3
#define GPIO_Pin_Number_4  4
#define GPIO_Pin_Number_5  5
#define GPIO_Pin_Number_6  6
#define GPIO_Pin_Number_7  7
#define GPIO_Pin_Number_8  8
#define GPIO_Pin_Number_9  9
#define GPIO_Pin_Number_10 10
#define GPIO_Pin_Number_11 11
#define GPIO_Pin_Number_12 12
#define GPIO_Pin_Number_13 13
#define GPIO_Pin_Number_14 14
#define GPIO_Pin_Number_15 15

//GPIO handle structures (pin level)
typedef struct {
Reg_def_t *pGPIOx;
GPIO_PIN_CONFIG_t pin_config;
}GPIO_handle_t;

//GPIO pin modes
#define GPIO_Mode_IN     0
#define GPIO_Mode_OUT    1
#define GPIO_Mode_ALT    2
#define GPIO_Mode_Analog 3
#define GPIO_Mode_IT_FT  4
#define GPIO_Mode_IT_RT  5
#define GPIO_Mode_IT_RFT 6


//GPIO pin output types
#define GPIO_OType0 0
#define GPIO_OType1 1

//GPIO pin PuPdControl
#define GPIO_NOPUPD 0
#define GPIO_PIN_PU   1
#define GPIO_PIN_PD   2


//GPIO pin speed control
#define GPIO_SpeedControl_LOW    0
#define GPIO_SpeedControl_MEDIUM 1
#define GPIO_SpeedControl_FAST   2
#define GPIO_SpeedControl_HIGH   3
/* PERIPHERAL CLOCK SETUP */
void GPIO_periClockControl(Reg_def_t *pGPIOx,uint8_t EnorDi);

/* INIT AND DEINIT */
void GPIO_Init(GPIO_handle_t *pGPIOhandle);
void GPIO_Deinit(Reg_def_t *pGPIOx);

/* read and write */
uint8_t GPIO_ReadFromInputPin(Reg_def_t *pGPIOx,uint8_t pinNumber);
uint8_t GPIO_ReadFromInputPort(Reg_def_t *pGPIOx);
void GPIO_WriteToOutputPin(Reg_def_t *pGPIOx,uint8_t pinNumber,uint8_t Value);
void GPIO_WriteToOutputPort(Reg_def_t *pGPIOx, uint16_t Value);
void GPIO_ToggleOutputPin(Reg_def_t *pGPIOx,uint8_t pinNumber);




#endif /* INC_STM32FXX_GPIO_DRIVER_H_ */