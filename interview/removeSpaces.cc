#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

bool xx(char *str)
{

    char *rec=NULL;
    int flagnum=0;
    char *cur=str;
    while(*cur!='\0')
    {
        if(' '==*cur)
        {
            ++flagnum;
            if(1==flagnum)
            {
                rec=cur;
            }
            ++cur;
            continue;
        }
        if(flagnum>1)
        {
            char *p1=rec+1;
            char *p2=cur;
            while(*p2!='\0')
            {
                *p1++=*p2++;
            }
            *(p1+1)='\0';
            cur=rec+1;
            flagnum=0;
            rec=NULL;
        }
        ++cur;
    }
    return true;
}

char* removeDuplicateSpace(char* str)
{
    if(str == NULL)
        return NULL;

    char* cur = str;
    while(*cur == ' ') {
        ++cur;
        if(*cur == '\0'){
            break;
        }
    }

    char* ret = cur;
    char* newCur = cur;
    bool removeLastSpace = false;

    //++cur; // one step to next
    for(;*cur != '\0';) {
        if(*cur == ' ') {
            *newCur++ = *cur;
            ++cur;
            while(*cur == ' ') {
                ++cur;
                if(*cur == '\0'){
                    removeLastSpace = true;
                    break;
                }
            }
        }
        else {
            *newCur = *cur;
            newCur++;
            cur++;
        }
    }
    if(removeLastSpace == true) {
        --newCur;
    }

    *newCur = '\0';

    return ret;
}

int main()
{
    // http://stackoverflow.com/questions/16338772/what-is-the-right-way-to-handle-char-strings
    // warning: conversion from string literal to 'char *' is deprecated [-Wdeprecated-writable-strings]
    char* testStr = "     he   ll  o a   ";
    testStr[2] = 'c';
    
    //char testStr[] = "     he   ll  o a   ";
    //char testStr[] = "     ";
    cout<<testStr<<endl; 
    //char* result = removeDuplicateSpace(testStr);
    //cout<<result<<endl;
    //cout<<strlen(result)<<endl;
    
    xx(testStr);

    cout<<testStr<<endl;
    cout<<strlen(testStr)<<endl;
}
