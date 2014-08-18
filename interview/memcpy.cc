void memcpy(void* dest, void* src, size_t len)
{
    char* destChar = (char*)dest;
    char* srcChar = (char*)src;
    while(len--) {
        *destChar++ = *srcChar++;
    }
}
