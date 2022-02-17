#include <stdio.h> 
#include <stdbool.h>
#include <string.h>
#define ptest "Output as expected"
#define ntest "Output not as expected"

int my_strlen(const char *str);
void my_concat(char *dest, char *src);
bool my_strcmp(char *lhs, char *rhs);

int main(void)
{
    // test string length 
    bool test = false;
    if(test)
    {
        char string[] = "string"; 
        int string_length = my_strlen(string);
        int expected = 6; 
        printf("%d = %d \n",expected, string_length);
        printf("%s \n", (expected == string_length)?ptest:ntest);
    
    }
    // test string concat 
    test = false; 
    if (test)
    {
        char dest[50] = "Hello "; 
        char src[] = "Alexander"; 

        my_concat(dest, src);
        printf("%s\n", dest);
    }
    test = true; 
    if (test)
    {
        char string1[] = "string ";
        char string2[] = "string";
        // which is lex lexigraphically greater? 
        int s1s2 = strcmp(string1, string2);  
        //expect negative 
        printf("%s\n\n", (s1s2 < 0)?ptest:ntest);
        // expect true 
        bool cmp = my_strcmp(string1,string2);
        printf("true = %s, %s\n\n", (cmp)?"true":"false", (cmp == true)?ptest:ntest);

    }
    return 0;
}

int my_strlen(const char *str)
{
    // cycle through array untill find null terminator incrementing counter
    int count = 0; 
    while(str[count] != '\0')
    {
        count++;
    }
    return count; 
}

void my_concat(char *dest, char *src)
{
    // use my strlen to check the lenght of both strings 
    // from dest[end+1] cycle through all chars of str2 until we reach then end; 
    // don't for get to append the dest string with a new \0 
    int dest_len = my_strlen(dest);
    int src_len = my_strlen(src); 
    for(int i = 0; i <= src_len; i++)
    {
        dest[dest_len+i] = src[i]; 
    }
}

bool my_strcmp(char *lhs, char *rhs)
{
    // assume the strings are the same 
    // cycle through lhs making < == or > comparisions with rhs entries
    // use condition lhs[i] != \0 for looping condition 
    // if different set to false 
    // check the i+1th entry of rhs, if not '\0' then set false 
    bool cmp = true;
    int str_len = 0;
    for(int i = 0; lhs[i] != '\0'; i++)
    {   
        str_len++; 
        if((cmp = (lhs[i] == rhs[i])) == false)
            break;
    }
    if (rhs[str_len] != '\0')
        cmp = false;
    return cmp; 
}