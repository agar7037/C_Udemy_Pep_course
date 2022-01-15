#include <stdbool.h> // pre-directive statement - look for header file stdbool.h
int main()
{
    enum Gender {male, female}; // declare data type 'enum' with name 'Gender' and fields '{male, female}'
    enum Gender myGender; // create an instance of enum 'Gender' with name 'myGender'
    bool isMale = true; // declare boolean variable 'isMale' defaulting to 'true' value (requires stdbool.h library)
    myGender = male; // set myGender to male - will recieve error if not male,female, 0, 1  
    isMale = myGender == 1; //fields of Gender indexable from 0, ie Gender[0] = male, Gender{1} = female
    isMale = myGender == male; 
    isMale = myGender == female; 
    isMale = myGender == 0;
    myGender = 1; 
    myGender = 3; 


    return 0; 

}