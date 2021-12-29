#include <stdbool.h>
int main()
{
    enum Gender {male, female};
    enum Gender myGender;
    bool isMale = true;
    myGender = male;
    isMale = myGender == 1;
    isMale = myGender == male; 
    isMale = myGender == female; 
    isMale = myGender == 0;
    myGender = 1; 
    myGender = 3; 


    return 0; 

}