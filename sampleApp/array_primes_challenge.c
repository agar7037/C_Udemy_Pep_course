/* 
challenge: find and display all prime numbers from 3 - 100
hard code 1 and 2 
output: each prime number separated by space on single line
vars: 
    .array to store each prime 
    .hard code 1st two in the array at init 
    .size of array will probably be less than 50 but use 100 just in case 
utilize loop to find primes up to 100

hints: prime is considered prime if it is not evenly divisible by any previous primes


*/ 

#include <stdio.h>
#include <stdlib.h>

int main(void){
//VARIABLES 
//prime array[100]
//prime_count for inner loop  
//FINDING PRIMES
    int prime_array[100] = {1,2};
    int prime_count = 2; 
    _Bool is_prime;
   
    for (int i = 3; i < 100; i = i + 2){
        is_prime = 1; // assume the number being checked is prime 
        for (int j = 1 ; i >= (prime_array[j]*prime_array[j]) && is_prime; j++) // check against square root condition and is prime condition
        { 
            
            if ((i % prime_array[j]) == 0) // check if current iteration is prime, change is prime flag to false if not prime
            {
                is_prime = 0; 
            }
        }
        if (is_prime == 1)
        {
                prime_array[prime_count] = i;
                prime_count++; 
        }   
    } 

//PRINTING PRIMES 

    for(int i = 0; i<prime_count; i++){
        printf("%d ", prime_array[i]);
    }

// iterate from 3 to 100 checking that the current value cannot be divisible by any previous
// how? outer loop represents the current value we are checking for 
// the inner loop runs for as many primes we have found in our array so we need a variable which stores number of primes 
/* finding primes 
    for (i = 3; i <= 100; i = i + 2) // check numbers from 3 - 100 ignoring even numbers as they're defs not prime
        for(j = 0; j < prime_count; j++) // compute loop as many times as we have primes 
            if i modulus prime_array[j] = 0 then we've found a number that is not prime
                break out of the loop; 
            else if j+1 = prime_count then we are on our last iteration of the loop 
                update prime count
                prime_array[j] = i; 

            else we haven't found a prime and we are not on the last iteration so
                continue to next interation;
*/

    return 0; 
}
