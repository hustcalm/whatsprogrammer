#include <stdio.h>

extern char** environ;

int main(int argc, char* argv[])
{
    char** env;

    printf("The environment variables: \n");

    for(env = environ; *env != NULL; ++env)
    {
        printf("%s.\n", *env);
    }

    return 0;
}
