#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <locale.h> 
#include <wchar.h>

int main(void)
{
    char character = 'a';
    (wchar_t)character; // illegal type conversion must be scalar type 
    printf("character: %S",character);

    return 0;
}