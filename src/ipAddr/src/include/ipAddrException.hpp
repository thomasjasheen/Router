#include <exception>
#include <stdio.h>
#include <string.h>
using namespace std;

#define ipAddrExcept(ip, errType)                                           \
                       ipAddrException( __FUNCTION__, __LINE__, ip, errType) 

enum ipAddrErrorType {
   ipAddrErrorTypeUnknown,
   ipAddrErrorTypeInvalidIpAddr
};

class ipAddrException : public exception {
   char functionName[64];
   unsigned int lineNo;
   char ipStr[16];
   ipAddrErrorType errorType;
   char ipAddrErrorDescription[256];

   void ipAddrErrorToStr() {
    switch(errorType) 
    {
       case ipAddrErrorTypeInvalidIpAddr:
         snprintf(ipAddrErrorDescription, 256, "EXCEPTION: %s:%d"
                  " InValid Ip Addr %s\n",
                   functionName, lineNo, ipStr);
         break;
         

       case ipAddrErrorTypeUnknown:
       default:
         snprintf(ipAddrErrorDescription, 256, "EXCEPTION: %s:%d"
                  " Unknown ip Addr Error %s\n",
                  functionName, lineNo, ipStr);
         break;
    }
   }
  public:
    ipAddrException(
                   const char *funName,
                   unsigned int line,
                   const char *ip,
                   ipAddrErrorType errType) {
      ENTRY(("in constructor = %s %d %s %d",
             funName,
             line,
             ip,
             errType));
      memset(ipStr, 0, 16);
      memset(functionName, 0, 64);
      strncpy(ipStr, ip, 16);
      ipStr[15]='\0';
      strncpy(functionName, funName, 64);
      functionName[63] = '\0';
      lineNo = line;
      errorType = errType;
      ipAddrErrorToStr();
   }
   const char * what () const throw () {
         return ipAddrErrorDescription;
   }
};
