/*
---------------------------------------------------------------------------------------------------------
Program: Russian Language learning 
Author: Alexander Garrett-Jones 
Date: Feb/2022
Version: Beta
Description: Console application for storing known Russian vocabulary including functions for self testing
---------------------------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include <string.h>

int NumEntries(const char *config, int buff_size);

int main(void)
{
    setlocale(LC_ALL,"");// Allow for Russian language input and output
    int BUFFERSIZE = sizeof(wchar_t)*100;
    const char *config = "russia_config.txt"; 
    int entries = NumEntries(config, BUFFERSIZE);
    printf("Number of entries; %d\n", entries);
    //struct definition
    struct word {
        char* Rus;
        char* En;
        char* Ru_sentence; // maybe change to array of sentences later
        char* En_sentence; 
    };

    //Open configuration file 
    FILE *fp = fopen("russia_config.txt","r"); 
    char* current_line;
    current_line = malloc(BUFFERSIZE);
    //_Bool delimit = 0; <-- checking for new word delimiter  
    if (fp == NULL){
        printf("File does not exist");
        return 0; 
    }
    // Assign members to structure from config file "russia_config.txt"
    struct word word1;
    int i = 0;
    while (fgets(current_line, BUFFERSIZE, fp) != NULL)
    {
        switch (i)
        {
        case 0:
            word1.Rus = malloc(strlen(current_line)*sizeof(wchar_t));
            strcpy(word1.Rus,current_line);
            break;
        case 1:
            word1.En = malloc(strlen(current_line)*sizeof(wchar_t));
            strcpy(word1.En,current_line);
            break;
        case 2: 
            word1.Ru_sentence = malloc(strlen(current_line)*sizeof(wchar_t));
            strcpy(word1.Ru_sentence,current_line);
            break;
        case 3:
            word1.En_sentence = malloc(strlen(current_line)*sizeof(wchar_t));
            strcpy(word1.En_sentence,current_line);
            break;
        default:
            printf("Something has gone wrong, entry has too many members, check config file: %d", i);
            break;
        }
        i++;
    }
    fclose(fp);
    free(current_line);

    //main menu variable declarations 
    int menu_select = 0; 
    char flush_buff;
    _Bool exit_prog = 0;
    int input_success = 0; 

    //program main menu selection 
    while (exit_prog == 0)
    {
        // print menu items 
        printf("You are in the main menu, please make a selection from the following:\n");
        printf("\t1. Vocabulary list\n");
        printf("\t2. Vocabulary list, no translation\n ");
        printf("\t3. Vocab test1, type English word given Russian\n");
        printf("\t4. Vocab test2, type Russian word given English\n");
        printf("\t5. Exit program\n");
        //check for correct input 
        input_success = scanf("%d",&menu_select);
        flush_buff = getchar();//consume newline char left in input buffer by scanf
        if (input_success == 0)
            {
                menu_select = 0;
            }
        //map selection to program functions 
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



/*function body definitions 
1. main menu function 
    inputs: none 
    ouputs: prints numbered menu; prompts user for input, pauses program to wait for response 
    uses switch statement to compare response to menu options 
    calls appropriate function 
*/
// Count the number of entries in the config file
int NumEntries(const char *config, int buff_size)
{
//Purpose: opens config file, counts the number entries by counting chosen delimeter character '|'
// open file, declare local variables
    FILE *fp = fopen(config,"r");
    char s[buff_size]; 
    int entry_count = 0;
// check that file exists 
    if (fp == NULL){
        printf("File does not exist");
        return 0; 
    }
// cycle through file counting delimeter char '|'
    while (fgets(s,buff_size, fp) != NULL)
    {
        if (s[0] == '|')
        {
            entry_count++; 
        }
    }
    fclose(fp);
    return entry_count;
}
/*
2. test function 1 
3. test function 2 
*/
