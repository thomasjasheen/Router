#include "./interface/include/interfaceModule.hpp"
#include "./hardware/Hardware.cpp"

  interfaceModule *interfaceModule::singletonInst = NULL;
  HardwareModule *HardwareModule::hmInst = NULL;
int main()
{




  interfaceModule *intfModule = interfaceModule::getIntfModuleInst();
  HardwareModule  *hmModule = HardwareModule::getHardwareModuleInst(intfModule);

  char lo1intfname[]= "Lookback 1";
  interface lbk1 = interface(1, lo1intfname, 0x01010101);
  intfModule->interfaceCreate(lbk1);
  intfModule->configPrint();

}
