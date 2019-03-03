#include "stdio.h"
#include <algorithm>
#include <vector>
#include <cstring>
#include "../observerDesignPattern/include/Observer.hpp"
#include "../observerDesignPattern/include/Subject.hpp"
#include "./include/interfaceModule.hpp"
class interface;

using namespace std;
typedef vector <interface> InterfaceCont;
typedef vector <interface>::iterator interfaceIterator;


	interface::interface(int Id, char* name, int addr): intfId(Id), ipAddress(addr) 
	{
		memcpy(intfName, name, 64);
	}
	bool interface::operator == (interface const &intf)
	{
		if(intfId == intf.intfId)
			return true;
		else
			return false;
	}
	void interface::interfaceDisplay()
	{
		printf("\ninterface %s {\n", intfName);
		printf(" intf id : %d\n", intfId);
		printf(" ip addr : %x\n", ipAddress);
		printf("}\n");
	}




   interfaceModule* interfaceModule::getIntfModuleInst()
   {
     if (singletonInst == NULL)
        singletonInst = new interfaceModule();
     return singletonInst;
   }
   
   //TODO: write to kernel to h/w or a file ect
   // give the info to other modules like fib
   // using observer pattern 
   void interfaceModule::interfaceCreate(interface intf)
   {
       intfCont.push_back(intf);
       notify(1, (void *)&intf);
   }

   //TODO:  write to kernel to h/w or a file ect 
   // give the info to other modules like fib
   // using observer pattern 
   void interfaceModule::interfaceDelete(interface intf)
   {
	   interfaceIterator iter;
	   iter = find(intfCont.begin(), intfCont.end(), intf);
	   if (iter != intfCont.end())
           {
	       intfCont.erase(iter);
	   }
	   else 
	   {
		   printf("interface not found");
	   }
    }
   void interfaceModule::configPrint()
   {
	   interfaceIterator iter;
	   for(iter = intfCont.begin(); iter != intfCont.end(); iter++)
		   iter->interfaceDisplay();
   }


//interfaceModule *interfaceModule::singletonInst = NULL;


#ifdef UNIT_TEST
int main()
{
	char lo1intfname[]= "Lookback 1";
	char fa1intfname[]= "FastEthernet 0/0";
	interfaceModule *intfModule = interfaceModule::getIntfModuleInst();
	interface lbk1 = interface(1, lo1intfname, 0x01010101);
	interface fa0  = interface(2, fa1intfname, 0x02020202);
	intfModule->interfaceCreate(lbk1);
	intfModule->interfaceCreate(fa0);
	intfModule->configPrint();
	intfModule->interfaceDelete(lbk1);
	intfModule->configPrint();

	return 0;

}
#endif
