#include <stdio.h> 
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#define ptest "Output as expected"
#define ntest "Output not as expected"
#define buffersize 200
// challenge 1 implement these three functions without using standard library functions
int my_strlen(const char *str);
void my_concat(char *dest, char *src);
bool my_strcmp(char *lhs, char *rhs);

// challenge 2 implement these functions

char *str_reverse(char *str); 
void bubble_sort_int(int array[], int n); // look up 
void bubble_sort_str(char *str[], int n);

//helper functions 

// takes input from fgets, tokenises and stores them in array of pointers given as parameter
void get_strings(char *buff,char **ptr, int n); 
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
    // test string compare
    test = false; 
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
    // test string reverse
    test = false; 
    if (test)
    {
        char str[] = "A very long string"; 
        char *string = str_reverse(str); 
        printf("reverse of str is: %s\n\n", string);
        // input string and reverse
        char buff[100]; 
        printf("Enter a string: ");
        fgets(buff, sizeof(buff), stdin);
        printf("\n");
        string = str_reverse(buff);
        printf("%s\n", string);
    }

    //test bubble sort - int array version 
    test =  false; 
    if(test)
    {
        int test[10] = {3,64,3,25,34,16,1,8,9,2};
        bubble_sort_int(test,10); 
        for(int i=0;i<10;i++)
        {
            printf("%d ", test[i]);
        }
    }
    // test bubble sort - array of strings version 
    test = false; 
    if(test)
    {
        //create three strings
        char str1[] = "one"; 
        char str2[] = "two"; 
        char str3[] = "zero"; 
        //create three pointers to those strings
        char *ptr1 = str1;
        char *ptr2 = str2; 
        char *ptr3 = str3;  
        //create pointer array 
        int n = 3;
        char *ptr[] = {ptr3, ptr1, ptr2};
        bubble_sort_str(ptr,n);
        for(int i = 0; i < n; i++)
        {
            printf("%s \n", ptr[i]);
        }
    }
    // test get input function 
    test = false; 
    if (test)
    {
        //prompt user for number of strings to enter, enforce only integer values 
        printf("input number of strings you want to sort:"); 
        int n = 0; 
        bool input_success = false; 
        while (!input_success)
        {
            input_success = scanf("%d", &n);
            while(getchar()!='\n'){}
            if (!input_success)
            {
                printf("Enter an integer value: ");
            }
    
        }
        // prompt user for n strings strings, initialise input buffer, pointer array, call custom input function
        printf("Please enter %d strings for sorting: \n", n);
        char buff[buffersize];
        char **ptr;
        ptr = malloc(n*sizeof(char**));
        get_strings(buff, ptr, n);
        for(int i = 0 ; i < n; i++)
        {
            printf("%s\n", ptr[i]);
        } 
        free(ptr);        
    }
    // linking of string bubble sort to input program
    test = true; 
    if (test)
    {
       //prompt user for number of strings to enter, enforce only integer values 
        printf("input number of strings you want to sort:"); 
        int n = 0; 
        bool input_success = false; 
        while (!input_success)
        {
            input_success = scanf("%d", &n);
            while(getchar()!='\n'){}
            if (!input_success)
            {
                printf("Enter an integer value: ");
            }
    
        }
        // prompt user for n strings strings, initialise input buffer, pointer array, call custom input function
        printf("Please enter %d strings for sorting: \n", n);
        char buff[buffersize];
        char **ptr;
        ptr = malloc(n*sizeof(char**));
        get_strings(buff, ptr, n);
        bubble_sort_str(ptr, n);
        printf("Your sorted string array is: \n"); 
        for(int i = 0; i < n; i++)
        {
            printf("%s \n", ptr[i]);
        }
  
        free(ptr); 
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
char *str_reverse(char *str)
{
    //find the lenght of input string 
    //allocate memory for reverse string 
    //reverse cycle through input string (starting from strlen -1)
    char *rev; 
    int length = strlen(str);
    rev = malloc((length+1)*sizeof(char));
    for(int i = (length-1), j = 0; i >= 0; i--, j++)
    {
        rev[j] = str[i];
    }
    rev[length] = '\0';
    return rev;
}

void bubble_sort_int(int array[], int n)
{
    // try with numbers first 
    //iterate through the array comparing the ith and the i+1th elements 
    //if the ith element > i+1th element swap them 
    // keep track of whether a swap has been made, repeat process until we have cycled through the array without swapping 
    //outer loop: reset swap flag; condition while swap flag
    bool swapped = true; 
    while (swapped)
    {
        swapped = false; 
        int temp = 0;
        for(int i = 0; i < (n-1); i++)
        {
            if(array[i] > array[i+1])
            {
                  //swap elements
                temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
                swapped = true;
            }
        }
    }
}

void bubble_sort_str(char *ptr[], int n)
{
    char *temp; 
    bool swapped = true; 
    while(swapped)
    {
        swapped = false; 
        for(int i = 0; i < (n-1); i++)
        {
            if(strcmp(ptr[i],ptr[i+1]) > 0)
            {
                temp = ptr[i];
                ptr[i] = ptr[i+1];
                ptr[i+1] = temp;
                swapped = true;
            }
        }
    }
}

void get_strings(char *buff,char **ptr, int n)
{
    fgets(buff,buffersize, stdin);
    // remove trailing newline char 
    buff[strlen(buff)-1] = '\0';
    char *token = NULL;
    char delim[] = " "; 
    token = strtok(buff, delim); 
    int i = 0; 
    while (token != NULL && i < n)
    {
        ptr[i] = token;
        token = strtok(NULL, delim);
        i++;
    }

    /*
    inputs: 
        .input buffer array
        .size of the input input buffer "buffersize" 
        .pointer to array of pointers 
        .number of elements in array of pointer 
    method: 
    . call f gets 
    . tokenise up to n elements modify the contents of pointer array ptr 
    . returns pointer to tokenised string 
    */
}





/*
Bubble sort string challenge 
input the number of strings: n 
input n strings 
options: 
    1.
    .use fgets to grab a space separated string 
    .tokenise the string up to n times; 
    .store strings in array of arrays (matrix)
    .have temporary buffer variable we can strcpy elements into for swapping 
    .perform bubble sort on 2D array using strcmp 

    .problem; don't know how large to make 2D array when initializing - can use variable length arrays though
    .problem; space leakage, user can put in as many strings as input buffer will allow; no way of forcing only the first three
    to be captured (ie input buff will take buffsize chars) - is problem? no input buff is large as input buff is declared regardless

    2. 
    . use scanf to grab three strings separately; but then we have no way of dynamically chaning size of our input
    3. 
    .  use fgets to grab a string and tokenise up to 3 strings
    .  have a 1D array of pointers to those strings as a VLA - perform bubble sort on this 
*/

