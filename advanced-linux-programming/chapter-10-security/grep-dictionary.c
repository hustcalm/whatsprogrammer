#include <stdio.h>
#include <stdlib.h>

int grep_for_word(const char* word)
{
    size_t length;
    char* buffer;
    int exit_code;

    length = strlen("grep -x ") + strlen(word) + strlen(" /usr/dict/words") + 1;
    buffer = (char*)malloc(length);
    sprintf(buffer, "grep -x %s /usr/dict/words", word);

    /* tricky is here, be carefl */
    exit_code = system(buffer);

    free(buffer);

    return exit_code == 0;
}
