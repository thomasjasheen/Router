#include "stdio.h"
#include <algorithm>
#include <vector>
#include <cstring>
#include "../../observerDesignPattern/include/Observer.hpp"
#include "../../observerDesignPattern/include/Subject.hpp"

class interface;

using namespace std;
typedef vector <interface> InterfaceCont;
typedef vector <interface>::iterator interfaceIterator;

class interface 
{
	int intfId;
	//TODO : dont use magic words
	char intfName[64];
	//TODO : change to the class
	int ipAddress;
	//TODO: add other paramenters like 
	//type, oper state, admin state

	public:

	interface(int Id, char* name, int addr); 
	bool operator == (interface const &intf);
	void interfaceDisplay();


};


class interfaceModule : public Subject
{
   static interfaceModule *singletonInst;
   InterfaceCont intfCont;

   public:

   static interfaceModule* getIntfModuleInst();
   
   //TODO: write to kernel to h/w or a file ect
   // give the info to other modules like fib
   // using observer pattern 
   void interfaceCreate(interface intf);

   //TODO:  write to kernel to h/w or a file ect 
   // give the info to other modules like fib
   // using observer pattern 
   void interfaceDelete(interface intf);
   void configPrint();

};

