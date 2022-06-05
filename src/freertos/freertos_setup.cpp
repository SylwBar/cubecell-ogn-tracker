#include "Arduino.h"
#include "FreeRTOS.h"

extern "C" {
extern void xPortPendSVHandler(void);
extern void xPortSysTickHandler(void);
extern void vPortSVCHandler(void);
}; 

void FreeRTOSSetup()
{
  CyIntSetSysVector(CY_INT_IRQ_BASE + SVCall_IRQn, (cyisraddress)vPortSVCHandler);
  CyIntSetSysVector(CY_INT_IRQ_BASE + PendSV_IRQn, (cyisraddress)xPortPendSVHandler);
//CyIntSetSysVector(CY_INT_IRQ_BASE + SysTick_IRQn, (cyisraddress)xPortSysTickHandler);
  CySysTickSetCallback(0, xPortSysTickHandler);
}

