char* strcpy(char* destStr, const char* srcStr)
{
    if(destStr == NULL || srcStr == NULL)
        throw "bad arguments";

    char* destStrResult;
    while((*destStr++ = *srcStr++) != '\0');
    return destStrResult;
}
