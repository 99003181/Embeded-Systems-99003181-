#include<stdint.h>
#define SRAM_START 0x20000000
#define SRAM_SIZE (128 * 1024)
#define SRAM_END  ((SRAM_START) + (SRAM_SIZE))

#define STACK_START	SRAM_END

void Reset_Handler(void);
void NMI_Handler(void)        __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void)  __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler(void)  __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler(void)  __attribute__((weak, alias("Default_Handler")));
void Usage_Fault_Handler(void)  __attribute__((weak, alias("Default_Handler")));
void SVCall_Handler(void)  __attribute__((weak, alias("Default_Handler")));
void Debug_Monitor_Handler(void)  __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler(void)  __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler(void)  __attribute__((weak, alias("Default_Handler")));
void WWDG_Handler(void)  __attribute__((weak, alias("Default_Handler")));


uint32_t vectors[] __attribute__((section(".isr_vector")))= {
	STACK_START,
	(uint32_t)&Reset_Handler,
	(uint32_t)&NMI_Handler,
	(uint32_t)&HardFault_Handler,
	(uint32_t)&MemManage_Handler,
	(uint32_t)&BusFault_Handler,
	(uint32_t)&Usage_Fault_Handler,
	0,
	0,
	0,
	0,
	(uint32_t)&SVCall_Handler,
	(uint32_t)&Debug_Monitor_Handler,
	0,
	(uint32_t)&PendSV_Handler,
	(uint32_t)&SysTick_Handler,
	(uint32_t)&WWDG_Handler,

};

void Default_Handler(void)
{
	while(1);
}

void Reset_Handler(void)
{
	


	
}