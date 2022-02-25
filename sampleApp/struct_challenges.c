#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define Buffsize 30
#define currentyear 2022
// struct definitions 
struct Employee 
{
    char *name; 
    struct 
    {
        int day; 
        int month; 
        int year;
    }hireDate;
    float salery; 
};
typedef struct Employee employee;
//gets information from stdin assigns to struct fields 
void getName(employee *pstr);
void getHireDate(employee *pstr);
void getSalery(employee *pstr);
void showEmpDetails(employee emps[], int N); 
char *spacing(char* name);
/*----------j------------------------------------------------------------------------------------------
                                             BEGIN PROGRAM
----------------------------------------------------------------------------------------------------*/
int main(void)
{
    employee employees[2];
    employee employee1 = {"Alexander Garrett-Jones",.hireDate = {12,3,2022}, 156000}; 
    employees[0] = employee1;
    employee *psEmp; 
    psEmp = &employees[1]; 
    getName(psEmp);
    getHireDate(psEmp);
    getSalery(psEmp);
    showEmpDetails(employees, 2); 

    
    free(employees[1].name); 
    return 0; 
}

void getName(employee *pstr)
{
    // parse a pointer to an employee struct - prompt user for input - check validity of input -
    // assign memory 
        char  buffer[Buffsize];
        bool input_success = false; 
        printf("Enter new employee name:"); 
        do 
        {
            input_success =  fgets(buffer, Buffsize, stdin);
            // check for null
            if (input_success == 0)
            {
                printf("Input has not been parsed");
                continue;
            }
            // check for digits or invalid use of special characters 
            for(int i = 0; i < strlen(buffer); ++i)
            {
                // digit case
                if(isdigit(buffer[i]))
                {
                    printf("Name must not contain numerical characters - ");
                    input_success = false;
                    break;
                }
                //punctuation case
                if (ispunct(buffer[i]))
                {
                    if (buffer[i]!= '-')
                    {
                        printf("Allowed punctuation charaters are: '-' only - ");
                        input_success = false;
                        break;
                    }
                }
            }
        } // end of do
        while(!input_success);
        // assign mememory to name string member 
        buffer[strcspn(buffer, "\n\r")] = 0; // clear newline 
        pstr->name = (char*)malloc(strlen(buffer)+1);
        if (pstr->name == NULL)
            printf("memory not allocated inside getinfo\n");
        strcpy(pstr->name, buffer);    
}
void getHireDate(employee *pstr)
{
    bool input = false; 
    int temp;
    printf("Enter hire date:\n");
    // enter year check valid input 
    printf("Year (numeric) - ");
    while(!input)
    {
        input = scanf("%d", &temp);
        while(getchar()!= '\n'){}
        if (!input || temp < 2000 || temp > currentyear)
        {
            printf("Invalid input - must be numerical between 2000:2022 -");
            input = false; 
            continue;
        }
        pstr->hireDate.year = temp;
    }
    // enter month check valid input 
    printf("Enter Month (numeric)- "); 
    input = false;
    while(!input)
    {
        input = scanf("%d", &temp);
        while(getchar()!= '\n'){}
        if (!input || temp > 12 || temp < 1)
        {
            printf("Invalid input - must be numerical between 1:12 - ");
            input = false; 
            continue;
        }
        pstr->hireDate.month = temp;
    }
    printf("Enter Day numeric -  ");  
    input = false;
    while(!input)
    {
        input = scanf("%d", &temp);
        while(getchar()!= '\n'){}
        if (!input || temp > 31 || temp < 1)
        {
            // include logic for testing month again days included here
            printf("Invalid input - must be numerical between 1:31 - ");
            input = false; 
            continue;
        }
        pstr->hireDate.day = temp;
    } 
    
    return; 
}
void getSalery(employee *pstr)
{
    int temp; 
    bool input = false; 
    printf("Input salery PA: ");
    while(!input)
    {
        input = scanf("%d", &temp);
        while(getchar()!= '\n'){};
        if(!input || temp<50000)
        {
            printf("Invalid input pls enter salery starting from 50,000 - "); 
            input = false; 
            continue;
        }
        pstr->salery = temp;
    }
    
}
void showEmpDetails(employee emps[], int N)
{
    printf("\n\n");
    printf("Employee\t\t       Date\t\t\tSalary\n");
    printf("Name\t\t\t       of hire\n"); 
    printf("--------------------------------------------------------------------------\n");
    for(int i = 0; i < N; ++i)
    {
        printf("%s%s%02d/%02d/%d\t\t%.2f\n", emps[i].name,
        spacing(emps[i].name),emps[i].hireDate.day,emps[i].hireDate.month,emps[i].hireDate.year,emps[i].salery);    
    }
}
// Generate the appropriate spacing between name column and Date of hire column in showEmpDetails function
/*
    .count the length of the name 
    .subtract this from the maximum spaces (30)
    .return a string containing that many spaces 
*/
char *spacing(char* name)
{   
    const int maxSpace = 30; 
    static char temp[31];
    temp[0] = '\0';  
    char space[] = " ";
    int diff = 0;
    diff = maxSpace - strlen(name);
    for(int i = 0; i<diff; ++i)
    {
        strcat(temp, space); 
    }
    return temp;
}
