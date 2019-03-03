#include <stdio.h>

#define PRINT(a) printf("%-10s:%05u::",__FUNCTION__,__LINE__); \
                 printf a ;                                    \
		 printf("\n");
