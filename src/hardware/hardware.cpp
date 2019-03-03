#include "stdio.h"
#include "../observerDesignPattern/include/Observer.hpp"
#include "../observerDesignPattern/include/Subject.hpp"

class HardwareModule : public Observer
{
 static HardwareModule *hmInst;

 HardwareModule (Subject *sub):Observer(sub)
 {

  
 }

 public:
 static HardwareModule* getHardwareModuleInst(Subject *sub)
 {
   if (hmInst != NULL)
      return hmInst;

   hmInst = new HardwareModule(sub);
 
   printf("HW ModuleInst CREATED\n");
   return hmInst;

 }
 int update(int type, void* t)
 {
   printf("\n GOT INTERFACE CREATION DATA FROM INTERFACE MODEULE");
 }
};

// HardwareModule *HardwareModule::hmInst = NULL;
