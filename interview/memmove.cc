#include <cstdio>

void memmove(void* dest, void* src, size_t len)
{
    char* destChar = (char*)dest;
    char* srcChar = (char*)src;
    if((dest > src) && (destChar < srcChar + len)) {
        
        // move from end
        char* destCharEnd = destChar + len;
        char* srcCharEnd = srcChar + len;
        while(len--)
        {
            *destCharEnd-- = *srcCharEnd--;
        }
    }
    // Do it the normal way
    while(len--)
    {
        *destChar++ = *srcChar++;
    }
}

int main()
{
    char src[] = "hello";
    char dest[] = "world";
    printf("src is %s.\n", src);
    printf("dest is %s.\n", dest);

    memmove((void*)dest, (void*)src, 6);

    printf("src is %s.\n", src);
    printf("dest is %s.\n", dest);
}
