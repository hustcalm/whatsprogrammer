#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int countMaxDigitalStr(char* output, char* input)
{
    if(NULL == input)
        return 0;
    const char* begin = NULL;
    int max_len = 0;
    for(const char*p = input; *p != '\0'; ) {
        if(!isdigit(*p)) {
            p++;
            continue;
        }
        // got a digital and move on
        int sum = 0;
        const char* tmp = p;
        for(; isdigit(*p); p++, sum++);
        if(sum > max_len) {
            max_len = sum;
            begin = tmp;
        }
    }
    memcpy(output, begin, max_len);
    return max_len;
}

int main()
{
    char output[100];  
    char input[100];  
    while (true)  
    {  
        cin >> input;  
        memset(output, 0 , sizeof(output));  
          
        int len = countMaxDigitalStr(output, input);  
          
        cout << len<<" " << output<<endl;  
    }  
}
