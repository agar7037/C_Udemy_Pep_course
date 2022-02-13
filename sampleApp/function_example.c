#include <stdlib.h> 
#include <stdio.h> 
// function prototypes/ declaration  
int add(int a, int b); 

// can define global variables here, these can be accessed anywhere in the function ie by main or by any functions 
// called within main 
int global_var = 8; 


int main(void)
{
    printf("global var inside main = %d\n", global_var); // can access global var inside main 
    int global_var = 14; // local variable masks global
    printf("local declaration of var name 'global_var' = %d\n",global_var);

    int x = 4; 
    int d = 6;
    int c = 0; 
    c = add(x, d); 
    printf("c = %d\n", c);
    div_t a; 
    a.quot = x/d; 
    a.rem = x%d; 
    printf("%d/%d yeilds %d, with %d remaining\n",x,d,a.quot,a.rem);

    if(x < d){
        int local_var = 0; // local automatic var 
    }

    //local_var = 7; // undefined in this scope 


    return 0; 
}
// function implementation/ definition 
int add(int a, int b ) 
{
    printf("global var inside add function = %d\n", global_var);// can access global var inside function add
    return a+b;
}