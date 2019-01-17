#ifndef _NEWEEPROM_H_
#define _NEWEEPROM_H_

 #ifdef SIMUL_MODE
  #include <vcl.h>
  #include <Param.h>
  #include <Parammodel.h>
  void NewEEPROM(char* Name, int Type, void* Adres, void const * Commentary,char* MyStr);
 #endif
#endif

