#include<stdio.h>
#include<include/print.h>
#include<ipAddr.cpp>

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

  IpMask(unsigned int ip, unsigned int mask) {
   ipAddr(ip);
   this.mask = mask;
  }

  IpMask(char *ipMask) {
   char cip[16];
   int ii = 0;
   while(*ipMask != '\0' && *ipMask != '\\' && i<16)
    ip[i] = ipMask[i++];
   ip[i] = '\0';
   ipAddr(ip);
   mask = atoi(ipMask[i]);
  }
}
