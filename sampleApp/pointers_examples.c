#include <stdlib.h> 
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void dummyfunction(int n);// function demonstration of function which does not alter variable 
void dummyfunction1(int *n); // demonstration of altering outside variable inside function using pointers 
//pointer arithmetic functions 
int arraySum(int array[], const int n); // uses pointers to iterate and sum elements of array 
void optimisedStrcpy(char *to, char *from);// uses pointer arithmetic to copy from one string to another  
int ptrStrLen(const char *str); //compute lenght of string using pointer arithmetic 
//pass by reference 
void passbyref(int *num);
int *passbyref1(int *num); 
void squarePassbyref(int *n);



int main(void)
{
// pointer examples up to pointers to strings 
    bool examples = false; 
    if(examples)
    {
    // passing pointers to functions allow us to modify variable values inside scope of function 
        int n = 5; 
        int *m = &n;
        //long num = 5L; // declare long number - without L automatically casts to int  
        dummyfunction(n);
        printf("n after dummy function %d\n\n",n);
        dummyfunction1(m);
        printf("n after dummyfunction1 %d\n\n", n);
        // warning when trying to print out pointer address for some reason 
        printf("pointer address %p \n", (void*)&m); // compiler expects %p to be pointer to some type but &m is pointer to pointer
        printf("size of pointer %zd\n\n", sizeof(m)); // pointer is 8 bytes (32 bit address) or 8 hexadecimal characters 
    // parsing array of int to scanf - do we need address? 

        int array[10] = {0};

        //printf("enter numbers: \n");
        //scanf("%d %d %d", array,array+1,array+2);
        //while(getchar()!='\n'){}

        for(int i = 0 ; i < 10 ; i++)
        {
            printf("%d\n", array[i]);
        }

        long long int disaster = 5LL; 
        printf("sizeof disaster = %zd\n\n", sizeof(disaster)); 
        long long int *pdis;  
    // *pdis = disaster; // actually gives you compiler warning - but not fatal error; may also cause segmentation fault at runtime

    // pointers to constant
        int value = 5; 
        const int *pvalue = &value;
    //illegal 
        printf("value: %d\n", value);
        *pvalue++; //doesn't actually throw any kind of error - but has no effect 
        printf("value after we try to change through constant pointer: %d\n", value);
        printf("altering the value itself: %d \n", ++value); 
    /*
    possible use: 
        .if we have a loop that changes the value of array elements but we want to keep particular elements constant 
        when they reach a specific value - assign const pointers to their address - replace element with const *ptr
        element will not be altered by any further looping process 
        .if we want to lock particular elements from further alteration in the program - conditional assignment to const pointer

    */
    // constant pointer 
        int *const pointer = &value; 
        printf("pointer content: %p\n", pointer);
        
        //pointer = &n; - will actually throw a fatal error 

    // void pointer 
        void *point = NULL; 
        int var1 = 8; 
        char var2 = 'x'; 
        float var3 = 0.032f; 
        printf("all of the following accessed from single pointer: \n");
        point = &var1; 
        printf("var1: %d\n",*(int*)point);
        point = &var2; 
        printf("var2: %c\n",*(char*)point);
        point = &var3;
        printf("var3: %.3f\n",*(float*)point);
        //printf("should throw warning or error: %c", *point); // illegal, must cast void type pointer to valid data type
        // we can use the same pointer to reference multiple different variables of different types so long as we know what 
        // type it is when we try and use that data from the pointer 
        
    // pointers to arrays
        
        int array1[10] = {1,2,3,4,5,6,7,8,9,10};
        int *parray1 = array1; 
        // all valid ways to access elements of the array 
        for(int i = 0; i < 10; i++)
        {
            printf("array1[i] = %d\n", array1[i]); 
            printf("parray1[i] = %d\n", parray1[i]);
            printf("*(parray1+i) = %d\n", *(parray1+i)); 
        }
        // permanently alter array pointer as we're incrementing 
        printf("address stored in parray1: %p\n", parray1);
        for(int i = 0; i < 10; i++) 
        {
            printf(" %d\n", *(parray1++)); //leaves the pointer outside bounds of array though 
        }
        printf("address stored in parray1 after loop: %p\n", parray1);
        
    // create pointers to the start and beginning of an array 
        int k = 0; 
        int A[100] = {0};
        int *pstartA = A;
        int *pendA = A;
        // fill the first 10 elemnts of our array 
        for(int i = 0; i<10; i++)
        {
            *(pstartA+i) = 5*i;
            k = i; // k is the index of the last element of the array 
            pendA = A+k; 
        }
        printf("A[k]: %d\n", A[k]); 
        printf("*pendA: %d\n", *pendA);
    // useful for algorithms that require us to keep track of how many elements we currently have stored in our array
    // if searching for a value in an array we know to be near the end can search from the last element 

        int sum = arraySum(A, k); 
    }

    // pointers challenge 1: 
    bool challenge = false; 
    if(challenge)
    {
         /*
         challenge: 
         write function that cal lenght of string, 
         takes const*char pointer 
         only determine lenght using pointer arithmetic 
         */
        char string[] = "string";
        int length; 
        length=ptrStrLen(string);
        printf("length of '%s' is %d\n", string, length);
        printf("compare to strlen: %d\n",strlen(string));

        char string1[] = "This is a really long string";
        length=ptrStrLen(string1);
        printf("length of '%s' is %d\n", string1, length);
        printf("compare to strlen: %d\n",strlen(string1));
    }
//Pass by reference pass by value subtleties - passed by value, passed by ref 
    bool examples2 = false;
    if(examples2)
    {
        int value = 103;
        int *num = &value; 
        passbyref(num); 
        printf("passbyref: is *num 10? %d\n\n", *num); 
        num = passbyref1(num);
        printf("passbyref1: is *num 10? %d\n\n", *num);
    }
// challenge 2 pass by reference 
    bool challenge2 = true; 
    if(challenge2)
    {
        /*
        Challenge: 
        write function which squares a number 
        define parameter int *ptr
        dereference value multiply by itself 
        */
       int num = 10; 
       int *pnum = &num; 
       squarePassbyref(pnum); 
       printf("num squared: %d\n", num); 
    }    
    return 0;
}

void dummyfunction(int n)
{
    n = n+1; // n becomes local variable - change of value does not extend outside of function scope
    return; 
}

void dummyfunction1(int *n) 
{
    *n = *n+1;
}
//more efficient array iteration 
int arraySum(int array[], const int n)
{
    int sum = 0, *ptr; // initialise pointer to be used as looping variable in for loop 
    int *const parrayEnd = array+n; //set a constant pointer to the end of the array 
    for(ptr = array; ptr<parrayEnd; ++ptr) // set pointer to address of first element of array, increment the pointer until last element 
    {
        sum += *ptr; 
    }
    // when exiting loop ptr will have the same value as parrayEnd
    return sum;
}
void optimisedStrcpy(char *to, char *from)
{
    while(*from)
    {
        *(to++)=*(from++);
    }
    *to = '\0';
}
// string lenght function for pointer challenge 1 
int ptrStrLen(char const *str)
{
    int length = 0; 
    char *ptr = str; 
    while(*ptr)
    {
        ptr++; 
    }
    length = ptr-str; 
    return length; 
}
// will not work because address num is passed by value and is then reallocated 
void passbyref(int *num)
{
    num = malloc(sizeof(int)); 
    *num = 10;
    return;
}
// Works because we are returned the newly allocated version of num 
int *passbyref1(int *num)
{
    num = malloc(sizeof(int)); 
    *num = 10;
    return num;  
}
void squarePassbyref(int *n)
{
    *n = (*n)*(*n);
}