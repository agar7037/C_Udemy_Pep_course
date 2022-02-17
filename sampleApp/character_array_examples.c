#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <stdbool.h> 
#include <ctype.h>


int main(void)
{
    size_t size_of_string;
// string length counting 
    bool section = false; 
    if (section == true) // string length functions 
    {
        const char mystring[] = "This is a string";
        size_of_string = strlen(mystring); // my string counts the number of characters not including the null char 
        printf("my string: %s ... characters in string: %zd\n", mystring, size_of_string);

    // what's happening inside strlen
        int char_count = 0; 
        while(mystring[char_count] != '\0')
        {
            char_count++;
        } 
        printf("my string: %s ... characters in string: %d\n", mystring, char_count); 

    // what about counting the sizeof(string)/sizeof(char)? 

        size_of_string = sizeof(mystring)/sizeof(char);
        printf("my string: %s ... characters in string: %zd\n", mystring, size_of_string);//method actually counts the null char
    // what happens when we try to change a constant string 
    }
// constant strings 
    section = false; // comment to turn off example 
    if (section == true) // constant strings
    {
        //uncomment to check 
        //const char string[] = "this is a string";
        char string[] = "this is a string";
        printf("Value of string before copy: %s ... length of string is %zd \n", string, strlen(string));
        char string1[] = "another string";
        strcpy(string, string1);
        printf("Value of string after copy: %s \n", string);
        char string2[] = "this string is larger than all the other strings"; 
        size_of_string = strlen(string); 
        strncpy(string, string2, size_of_string); 
        printf("truncated string2: %s ... length of string is %zd\n", string, size_of_string); 
        
        // allows you to change but flags an error at compile time warning that const qualifier from pointer target
    }
// string concatination
    section = false; 
    
    if (section)
    {
        char string[] = "This is a string "; 
        char string1[200] = "this string has extra space ";
        printf("string1: %s\n", string1); 
        printf("length of string1 %zd\n", strlen(string1));
        strcat(string1,string);
        printf("string1 after concatination: %s\n", string1);
        printf("length of string after concat %zd\n", strlen(string1)); 
        strcat(string1, string); 
        printf("string1 after double concatination call : %s \n", string1);
        printf("length of string after 2nd strcat %zd\n", strlen(string1));
        char string3[] = "third string";
        printf("length of string3: %zd\n",strlen(string3));
        strcat(string1, string3); 
        printf("expected length of string1 after third concat: 74\n"); 
        printf("actual length of string1 after 3rd concat: %zd\n",strlen(string1) ); 
        printf("%s\n", (strlen(string1)==74)?"Hurray":"Oh no");  
        strncat(string1, string3, 5); // CONCCATONATE ONLY UP TO 5 CHARACTERS 
        printf("expected length of string1 after third concat: 79\n"); 
        printf("actual length of string1 after 3rd concat: %zd\n",strlen(string1) ); 
        printf("%s\n", (strlen(string1)==79)?"Hurray":"Oh no");  
        
    }
// string compare - compares two strings in terms of their contents 
// if the strings are exaclty the same then a zero will be returned 
// if the strings diverge then the an ascii code comparision is performed on the first character that does not match 
// if lhs < rhs (ie lhs char lexigraphically precedes rhs) then return negative val 
// if lhs > rhs (ie lhs char    ''           follows rhs) then return positive val
    section = false; 
    if (section)
    {
        char string[] = "string";
        char string1[] = "also string";  
        printf("expected output strcmp: positive val\n");
        printf("actual output: %d\n", strcmp(string,string1));
        printf("%s\n",(strcmp(string,string1) > 0)?"hurray":"oh no");

        printf("expected output strcmp 2: negative\n");
        printf("actual output %d\n", strcmp(string1,string));
        printf("%s\n", (strcmp(string1,string)<0)?"hurray":"oh no"); 
          
        strncpy(string1,string, strlen(string1)); 
        printf("expected outpout strcmp 3: 0\n");
        printf("actual output: %d\n", strcmp(string,string1));
        printf("%s\n", (strcmp(string,string1)==0)?"hurray":"oh no");

        // strncmp peforms comparision up to the number of characters contained in the third argument 
    }
// pointers brief 
    section = false; 
    if (section)
    {
        int i = 5; 
        printf("the number stored in i = %d ... the address of i is %p\n",i, &i);
        printf("we can also make a pointer out of i \n"); 
        int *p = &i; 
        printf("the value of p is %p ... the address of i is %p\n", p, &i); 
        // p = i; // this raises error as we have told compiler that p is a pointer to an integer and we have overidden the contents
        // of p with the value of an integer, compiler interprets this as an address of value 5; 
        printf("the value of p now is %p\n", p);
        //printf("whats the value stored in address p? %d", *p); <-- leads to segmentation fault (core dumped)
        printf("The value stored at address pointed to by p is %d which is the same as i = %d\n", *p, i);
        printf("We can also have a pointer to a pointer\n\n"); 
        int **pp = &p; 
        printf("&pp should be the address of pp: %p\n", &pp);
        printf("pp should be the address which pp stores; ie a pointer to p: %p\n", pp);
        printf("the address of p, &p, should return the same value as above: %p\n", &p); 
        printf("dereferencing pointer pp, *pp gives you p gives you address of &i: %p = %p = %p\n",*pp, p, &i );
        printf("dereferencing pp twice, **p, should give you value of i: %d = %d = %d\n\n", **pp,*p,i);
      
     // pointers to strings  
        char string[] = "this is a string";
        printf("address of string = %p\n", &string); 
        printf("value of string[1] = %c = %c\n\n", *string, string[1]);
        char *ptr = string; // pointer to a string 
        printf("ptr is a pointer to string: %p = %p \n", ptr, &string); 
        printf("dereferencing ptr, *ptr gives you string[0]: %c\n", *ptr); 
        printf("using ptr with string format %%s gives you: %s\n\n", ptr); 
        printf("altering the value of string should also affect ptr\n"); 
        char string1[] = "Hello"; 
        strcpy(string, string1); 
        printf("accessing ptr again: %s\n\n", ptr);
        //string = string1; can't modify a pointer to a string 
        // pointer to char 
        char character = 'A'; 
        char *charptr = &character;
        strcat(string, "hello"); 
        printf("String: %s\n", string);
        printf("This should printf out garbage: %s", charptr); 
    }
// string searching 
    section = false; 
    if (section)
    {
    // single character search 
        char string[] = "This is a string"; 
        char *charptr = strchr(string, 'a');
        printf("a is at pos %ld\n\n", charptr - string); // displays the index of the character found 
        // replace the a with different character 
        *charptr = 'b'; 
        printf("This is our string %s\n\n", string);
        printf("printf string from charptr: %s\n\n", charptr); 
        printf("accessing element from charptr: %c\n\n", charptr[4]); 
        // character not found case 
        charptr = strchr(string, 'z'); 
        printf("%s\n\n", (charptr == NULL)?"strchr has returned NULL":"whats up?"); 
    
    // substring search 
        char string1[] = "This is a really really long string and we want to find the word 'dog' inside of it"; 
        char target[] = "dog"; 
        char *dogPtr = NULL; 
        dogPtr = strstr(string1, target); 
        if (dogPtr == NULL)
        {
            printf("the word 'dog' has not been found\n"); 
        }
        else 
            printf("the word dog has been found at index: %ld\n", dogPtr - string1);
        
        printf("the rest of the string from dog is: %s\n", dogPtr); 

    }

// tokenising a string 
    section = false;
    if(section)
    {
        //count the occurances of 'and' in a string
        char string[] = "my name is Alex, and this is a string, and there should be three counts of and in this string\n\n";
        char delim[] = "and";
        char *token = NULL;
        int andCount = 0;
        token = strtok(string, delim);
        do 
        {
            printf("%s\n", token); 
            token = strtok(NULL, delim);
            andCount++;
            
        }
        while(token != NULL);

        // this basically doens't work because the program tokenises string when it finds any character found
        // in the delim string; ie string will become: my, me is Alex, this is, stri, g, there shoul, be three cou, of, i , this stri 
//correct way 
        char string1[] = "andandandandand"; // expect to find 5 ands

        andCount = 0; 
        token = strstr(string1, "and"); 
        while (token != NULL)
        {
            token = strstr(token+strlen("and"), "and"); 
            andCount++;
        }
        printf("number of ands expected = 5, returned = %d\n\n", andCount);

// proper use of token 
        char string2[80] = "token1 -token2 -token3 -token4 -token5";
        token = NULL; 
        char delim1[] = "-"; 
        token = strtok(string2, delim1);
        while (token)
        {
            printf("%s\n", token); 
            token = strtok(NULL, delim1);
            
        }
// String analysing; counting numbers, letters, punctuation marks and spaces 
        char buffer[101]; 
        printf("Enter a string 100 characters or less: "); 
        fgets(buffer, sizeof(buffer), stdin); // preferred input method gest input without leaving newline in input buffer
        printf("\n");
        printf("you entered: %s\n\n", buffer);

        int digit_count = 0; 
        int letter_count = 0; 
        int space_count = 0; 
        int punct_count = 0; 
        for(int i = 0; i < strlen(buffer); i++)
        {
            if(isalpha(buffer[i]))
                letter_count++;
            else if(isdigit(buffer[i]))
                digit_count++;
            else if(isspace(buffer[i]))
                space_count++;
            else if(ispunct(buffer[i]))
                punct_count++;
        }
        printf("Your string contained %d letters, %d digits, %d spaces & %d punctuation marks"
        , letter_count, digit_count,space_count,punct_count
        );
    }

// string manipulation - conversion 
    section = true; 
    if (section)
    {
    // to upper - for lower just change to tolower()
        char string[] = "this is a lower case string";
        for(int i = 0; (string[i]=(char)toupper(string[i])) != '\0'; i++); // can have an assignment in looping condition 
        printf("string should be upper-case %s\n\n", string);
    }
// string to numbers  
    //get input check for validation 
    bool input_success = false; 
    char buff[100*sizeof(char)+1];
    while(!input_success)
    {   
        printf("Enter any numbers, do not input letters (spaces allowed): ");
        fgets(buff, sizeof(buff)-1, stdin);
        printf("\n");
        input_success = true; // asume it's true
        for(int i = 0; i < strlen(buff); i++)
        {
            if((!isdigit(buff[i]))&&(!isspace(buff[i])))
                input_success=false;    
        }
    }
    //delimit numbers by spaces through tokenising string 
    char delim[] = " ";
    char *token = NULL; 
    token = strtok(buff,delim);
    int count = 0; 
    count += atoi(token);
    while(token != NULL)
    {
        token = strtok(NULL, delim);
        if(token != NULL)
            count += atoi(token); 

    }
    printf("total sum of input: %d\n\n", count);

    return 0;
}