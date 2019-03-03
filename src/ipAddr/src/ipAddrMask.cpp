#include <stdio.h>
#include "include/print.h"
#include "ipAddr.cpp"

class IpMask : public ipAddr 
{
 unsigned int mask;

 public:
  unsigned int getMask() {
   return mask;
  }
  void setMask(unsigned int m) {
   if(isV4() && m>=0 and m<=32)
    mask = m;
  }

  IpMask(unsigned int ip, unsigned int msk):ipAddr(ip) {
   mask = msk;
  }

  IpMask(char *ipMask) {
   char cIp[16];
   int i = 0;
   while(*ipMask != '\0' && *ipMask != '\\' && i<16){
    cIp[i] = ipMask[i++];
   }
   cIp[i] = '\0';
   setCharToIpAddr(cIp);
   mask = atoi(ipMask+i);
  }
};
