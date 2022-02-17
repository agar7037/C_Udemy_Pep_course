
/* 
Challenge: write three functions 
    1. GCD - find greatest common divisor of two unsigned integers return result 
    2. abs - find the absolute value of float input 
    3. sqrt - find the sqrt of a number - return -1 and print error message if negative number parsed;
        use abs() as a helper function  
*/

//PRE-DIRECTIVES 
//------------------------------------------------------------------------------------------------
#include <stdio.h> 
#include <stdlib.h> 
#define MAX(a,b) (((a) > (b)) ? (a) : (b)) // max macro used in GCD algorithm 
#define MIN(a,b) (((a) < (b)) ? (a) : (b)) // min macro used in GCD alogrithm 

// Function Declarations 
//------------------------------------------------------------------------------------------------
int GDC(unsigned int a, unsigned int b); 
float absolute(float a);
float square_root(float a);


//BEGIN PROGRAM
//------------------------------------------------------------------------------------------------

int main(void)
{ 

// GCD test 
//------------------------------------------------------------------------------------------------
    int a = 4; 
    int b = 2; 
    int gdc = GDC(a,b); 
    printf("GDC of %d, and %d is %d\n", a,b,gdc); 

    a = 10; 
    b = 12; 
    gdc = GDC(a,b);
    printf("GDC of %d, and %d is %d\n", a,b,gdc); 

    a = 14; 
    b = 21; 
    gdc = GDC(a,b);
    printf("GDC of %d, and %d is %d\n", a,b,gdc); 
    //what happens if we parse negative numbers? 
    a = -14; 
    b = 21; 
    gdc = GDC(a,b); // calling on a negative number converts var 'a' to some large number because of sign bit miss translation
    printf("GDC of %d, and %d is %d\n", a,b,gdc);  

    // two primes test expect 1 
    a = 11; 
    b = 7; 
    gdc = GDC(a,b);
    printf("GDC of %d, and %d is %d\n", a,b,gdc);    
    // test from video 
    a = 35; 
    b = 150; 
    gdc = GDC(a,b);
    printf("GDC of %d, and %d is %d\n", a,b,gdc);   
// ABSOLUTE VALUE TEST 
//------------------------------------------------------------------------------------------------
    float A = 8.0f; 
    A = absolute(A);
    printf("A = %.2f\n", A);
    
    A = -8.0f; 
    A = absolute(A); 
    printf("A = %.2f\n",A);

    int B = -9; 
    B = absolute(B); 
    printf("B = %d\n", B); 

// SQUARE ROOT TEST 
//------------------------------------------------------------------------------------------------
    // negative 
    a = -1; 
    float x = square_root(a); 
    printf("square root x: %.2f\n", x);

    // perfect square - expect 2 
    x = 4.0f; 
    x = square_root(x); 
    printf("square root x: %.2f\n",x); 

    // another perfect square - expect 8 
    x = 64.0f; 
    x = square_root(x); 
    printf("square root x: %.2f\n",x); 

    // transcendental number - sqrt(2) expect approx 1.41

    x = 2.0f; 
    x = square_root(x); 
    printf("square root x: %.2f\n",x);

    // sqrt(8) expect approx 2.8284
    x = 8.0f; 
    x = square_root(x); 
    printf("square root x: %.4f\n",x);
//------------------------------------------------------------------------------------------------
    return 0; 
}

// FUNCTION DEFINITIONS 
//------------------------------------------------------------------------------------------------
// uses Euclidean algorithm to recursively find the GDC of two positive numbers 
int GDC(unsigned int a, unsigned int b) 
{   
    int gdc; 
    int r; 
    if(a == 0)
        gdc = b;
    else if(b == 0)
        gdc = a;
    else 
    {
        r = MAX(a,b)%MIN(a,b);
        gdc = GDC(MIN(a,b),r);
    }
    return gdc;    
}
// abs returns absolute value of a float a 
float absolute(float a)
{
    if (a < 0)
        a = a*(-1); 
    return a; 

}
// uses Newton Raphson method for computing the square root. 
float square_root(float a)
{
    float sqR; 
    float tol = 0.000001; 
    float xi = a; 
    float xip1 = 0;
    float tol_check = 0;
    if(a < 0){
        printf("This algorithm does not support negative numbers\n"); 
        sqR = -1; 
    }
    else 
    {
        do
        {
            xip1 = (xi + a/xi)/2;
            tol_check = xi-xip1; 
            xi = xip1; 
        } 
        while (absolute(tol_check) >= tol);
        sqR = xip1;
        // newton raphson method for compute square root 
        /*//x_(i+1) = (x_i + x0)/2;
            when x_i - x_(i+1) < tol finish 
        */   
    }
    return sqR; 
}