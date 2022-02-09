#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{   
    const char* config = "russia_config.txt";
    FILE *fp = fopen(config,"r");
    int BUFFERSIZE = sizeof(wchar_t)*100; 
    char s[BUFFERSIZE]; 
    int entry_count = 0;
// check that file exists 
    if (fp == NULL){
        printf("File does not exist");
        return 0; 
    }
// cycle through file counting delimeter char '|'
    while (fgets(s,BUFFERSIZE, fp) != NULL)
    {
        if (s[0] == '|')
        {
            entry_count++; 
        }

    }
    
    printf("number of entries: %d", entry_count);
    fclose(fp);
    return entry_count; 
}