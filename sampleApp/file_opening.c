#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <wchar.h>

int main(void)
{
    FILE *fp = fopen("russia_config.txt","r");
    int BUFFERSIZE = sizeof(wchar_t)*100; 
    char* s;
    char* EOF_check;
    _Bool delimit = 0; 
    size_t Ru_size;   
    if (fp == NULL){
        printf("File does not exist");
        return 0; 
    }
  /*
    size_t string_count; 
    fgets(s, 50, fp);
    string_count = strlen(s);
   // printf("string_count: %zd",string_count);
    char str[] = "This is the first line \n";
    printf("string from file: %s, it's length is %zd\n",s, string_count);
    string_count = strlen(str);
    printf("string from file hard coded length is %zd\n",string_count);
    
    */
    

    /* for reading one line at a time 
    EOF_check = fgets(s,sizeof(s), fp);
    printf("file line1: %s", s);
    EOF_check = fgets(s,sizeof(s), fp);
    printf("Is this the second line? %s", s);
    EOF_check = fgets(s,sizeof(s),fp);
    printf("what is s now? %s", s);
    fclose(fp);
    return 0; 
    */
// looping method 
/*
   while (fgets(s, sizeof(s), fp) != NULL)
   {
       printf("%s",s);
       if (s[0] == '|')
       {
           printf("file has reached delimiter"); 
       }

   }

*/ 
// Frame work for assigning values to struct members from file 
    struct words {
        char* string1;
        char* string2; 
        char* string3;
        char* RusStr;
    };

    struct words word; 
    int i=0;
    while (fgets(s, BUFFERSIZE, fp) != NULL)
    {
        switch (i)
        {
        case 0:
            word.string1 = malloc(strlen(s));
            strcpy(word.string1,s);
            break;
        case 1:
            word.string2 = malloc(strlen(s));
            strcpy(word.string2,s);
            break;
        case 2: 
            word.string3 = malloc(strlen(s));
            strcpy(word.string3,s);
            break;
        case 3: 
            word.RusStr = malloc(strlen(s));
            strcpy(word.RusStr,s);
            break;

        default:
            printf("something has gone wrong");
            break;
        }
        i++;
   }

    printf("string1: %s",word.string1);
    printf("string2: %s",word.string2);
    printf("string3: %s",word.string3);
    printf("Russian String: %s", word.RusStr);
    size_t s_size = strlen(s);
    printf("size of s: %zd\n", strlen(s));
    printf("first char of russian string: %s", word.RusStr);
    fclose(fp);

 /*
fgets notes: 
    .Subsequent calls from fgets will read the next line - lines are delimited by \n char 
    .fp is a pointer to file obtained by using fopen
    .fp is null if the file does not exist - use for file checking 
    .when all lines are written (reached EOF) fgets returns null, subsequent calls to f gets does not change 
        value of string variable parameter - can read whole file looping over until fgets == NULL  
    */
}