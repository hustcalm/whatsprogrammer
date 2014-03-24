#include <stdio.h>

int main()
{
    int retval = system("ls -al ~");

    return retval;
}
