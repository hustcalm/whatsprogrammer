#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cassert>

using namespace std;

template <typename Iterator>
bool Compare(Iterator first1, Iterator last1, Iterator first2, Iterator last2)
{
    for(; first1 != last1 && first2 != last2; ++first1, ++first2){
        if(*first1 < *first2) return true;
        if(*first2 < *first1) return false;
    }

    return first1 == last1 && first2 != last2;
}

bool StrCmp(const char* str1, const char* str2)
{
    assert(NULL != str1);
    assert(NULL != str2);
    return Compare(str1, str1 + strlen(str1), str2, str2 + strlen(str2));
}

int main()
{
    const char* str1 = "hello";
    const char* str2 = "world";
    if(StrCmp(str1, str2) == true) {
        cout<<str1<<" is before "<<str2<<endl;
    }
}
