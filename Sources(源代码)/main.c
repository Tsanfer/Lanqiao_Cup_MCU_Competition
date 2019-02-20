#include "common.h"
#include "intrins.h"

void SysInit(void)
{
  buzzInit();
  relayInit();
  ledInit();
  hc138Init();
  Timer0Init();
  Timer1Init();
  ET0=1;    
  ET1=1;
  EA=1;
}

void main(void)
{
  SysInit();
  while(1)
  {
    ;
  }
}