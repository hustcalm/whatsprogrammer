#include <iostream>

char* strcpy(char* strDest, const char* strSrc)
{
    if(strDest == NULL || strSrc == NULL) {
        throw "bad argument(s)";

    }

    char* strDestCpy = strDest;
    while((*strDest++ = *strSrc++) != '\0')
        ;

    return strDestCpy;
}
