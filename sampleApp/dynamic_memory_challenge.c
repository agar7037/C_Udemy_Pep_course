/*
.write program that allows user to input text string. program will print 
text that was inputed
.program uses dynamic memory allocation 
.user enters limit of string they are entering 
.no character arrays are implemented only char *ptr
. free all memory allocated
*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(void)
{
    char *pstring = NULL; 
    int charLimit = 0; 
    printf("set character limit: ");
    while(scanf("%d", &charLimit) == 0)
    {
        printf("invalid input enter an integer: ");
        while(getchar() != '\n'){}
    }
    while(getchar() != '\n'){}

    printf("you entered: %d\n", charLimit);
    pstring = calloc((size_t)charLimit, sizeof(char));
    if (pstring == NULL )
    {
        printf("Memory not allocated on line 29\n"); 
        abort();
    }
    printf("Enter the string: \n");
    fgets(pstring, charLimit, stdin);
    *(pstring+strlen(pstring)-1) = '\0'; // clear newline 
    printf("you entered: \n '%s'", pstring);

    free(pstring);
    

    return 0;
}
