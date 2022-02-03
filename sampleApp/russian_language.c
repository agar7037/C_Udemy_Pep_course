#include <stdio.h>
#include <wchar.h>
#include <locale.h>



int main(void)
{
    setlocale(LC_ALL,"");
    //struct definitions here 



    //dictionary init


    // variable declarations 
    int menu_select = 0; 
    _Bool exit_prog = 0; 


    //program main menu function call 
    printf("You are in the main menu, please make a selection from the following:\n");
    printf("\t1. Vocabulary list\n");
    printf("\t2. Vocabulary list, no translation\n ");
    printf("\t3. Vocab test1, type English word given Russian\n");
    printf("\t4. Vocab test2, type Russian word given English\n");
    printf("\t5. Exit_program\n");

    while (exit_prog == 0)
    {
        scanf("%d",&menu_select);
        getchar();
        
        switch (menu_select)
        {
        case 1 :
            printf("Must implement call to vocab list\n");
            break;
        case 2 :
            printf("Must implement call to vocab list test\n");
            break;
        case 3 : 
            printf("Must implement call to test1\n");
            break;
        case 4 : 
            printf("Must implement call to test2\n");
            break;
        case 5 :
            exit_prog = 1;
            break;
        default:
            printf("Invalid selection, please enter the number of the menu item you would like\n");
            break;
        }

    } 




    return 0;
}


/*function definitions 
1. main menu function 
    inputs: none 
    ouputs: prints numbered menu; prompts user for input, pauses program to wait for response 
    uses switch statement to compare response to menu options 
    calls appropriate function 



2. test function 1 
3. test function 2 




*/