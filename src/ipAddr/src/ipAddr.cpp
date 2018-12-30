#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "include/print.h"

#define IPSTRLEN 16

class ipAddr {
   // TODO make it copactible across platform by making int 32 bit
   int addr[4];
   int* getaddrLoc()
   {
    return &addr[0];
   }
   public:
 
   ipAddr()
   {
     memset(&addr, 0, sizeof(addr));
   }
   ipAddr(const ipAddr& input)
   {
     memcpy(&addr, input.addr, sizeof(addr));
   }

   ipAddr(const int ipv4)
   {
     memset(&addr, 0, sizeof(addr));
     addr[3] = ipv4;
     PRINT(("in constructor addr4 = %x", addr[3]));
   }

   ipAddr(const int* ipv6)
   {
     memcpy(&addr[0], ipv6, sizeof(addr));
   }

   // supports only ipv4 for now
   ipAddr(const char* ip)
   {
    char  temp[8];
    int i=0;          // No of chars per octet (3)
    int octet=0;      // to store each octet every time
    int noOfOctet = 4;
    memset(addr, 0, sizeof(addr));
    PRINT(("in constructor addr6 = %s", ip));
    while(*(ip) != '\0' && noOfOctet)
    { 
     
     PRINT(("in constructor addr6 outside loop %c", *ip));
     i=0;
     octet =0; 
     noOfOctet--;
     while(*ip !='.' && i < 3 && *ip != '\0')
     {
      PRINT(("in constructor addr6 inside loop *ip = %c", *ip));
      temp[i++] = *(ip++);
      PRINT(("in constructor addr6 inside loop temp = %s", temp));
     }
     temp[i] = '\0';
     octet = atoi(temp);// check octect > 0 and < 255 
     addr[3] |= octet << 8*(noOfOctet);
     PRINT(("in constructor addr6 outside loop addr = %x", addr[3]));
     ip++;
    }
  
   }

   //TODO create proper conditions and endianess 
   int isV4()	
   {
     if(!addr[0] && !addr[1] && !addr[2] && addr[3])
     {
      return 1;
     }
     return 0;
   }

   void toChar(char *array)
   {
     if (isV4())
     {
      int a = addr[3];
      snprintf(array, 16, "%d.%d.%d.%d",
		((a & 0xff000000)>>24),
		((a & 0x00ff0000)>>16),
		((a & 0x0000ff00)>>8),
		(a & 0x000000ff));
      PRINT(("addr4 = %x str =%s ", addr[3], array));
     }
     else
     {
       PRINT(("else v6 addr= %x %x %x %x str =%s ",
              addr[0], addr[1], addr[2], addr[3], array));
     }
   }


 };

#define UT

#ifdef UT
int main()
{
 int a = 0x0a010201;
 char str[16];
 ipAddr* addr1 = new ipAddr(a);
 addr1->toChar(str);
 printf("\n addr1 = %s\n",str);

 ipAddr addr2(a);
 addr2.toChar(str);
 printf("\n addr2 = %s\n",str);

 ipAddr addr3("1.2.3.4");
 addr3.toChar(str);
 printf("\n addr3 = %s\n",str);

 ipAddr addr4("11.12.13.14");
 addr4.toChar(str);
 printf("\n addr4 = %s\n",str);
}
#endif
