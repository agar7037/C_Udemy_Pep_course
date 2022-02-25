#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#define BUFFSIZE 100

// struct declaration to be used inside get info function 
struct myName 
{
    char *first; 
    char *last;
};
//get info declaration 
void getinfo(struct myName *ptr); 

int main(void)
{
//anonymous struct declaration  
    struct 
    {
        int day; 
        int month; 
        int year; 
    } today = {27,12,1989}; 
    
    printf("my birthday = %d/%d/%d\n", today.day,today.month,today.year);
// normal declaration 
     struct date
    {
        int day; 
        int month; 
        int year; 
    };   
//instantiation & initialisation
    struct date tod = {23,12,1980};
    printf("todays date is %d/%d/%d\n", tod.day,tod.month,tod.year);

// compound literal - changing values 

    tod = (struct date){24,12,1980};
    printf("tomorrows date is %d/%d/%d\n", tod.day,tod.month,tod.year);

// partial initialisation 
    struct date partial = {.day = 2, .year = 2001 }; // unint fields implicitly init to 0 
    printf("partiallly init struct: %d/%d/%d\n\n", partial.day,partial.month, partial.year);


//Struct Arrays 
//instantiate and init
struct date dates[3] = 
{
    {24,3,89}, //init for dates[0]
    {22,7,89}, // init for dates[1]
    {23,6,89} // init for dates[2]
};

for(int i = 0; i < 3; ++i)
{
    printf("date[%d] is %d/%d/%d\n\n",i, dates[i].day, dates[i].month, dates[i].year);

}

// partial init
// three different kinds of struct array init
                    //      first two          spec index       spec index spec field
struct date dates1[5] = {{12,1,23},{2,2,29}, [3] = {23,1,20}, [2].year = 1980};
for(int i = 0; i < 5; ++i)
{
    printf("date[%d] is %d/%d/%d\n",i, dates1[i].day, dates1[i].month, dates1[i].year);

}

// struct with array field 
struct Month 
{
    int numDays; 
    char name[4]; 
};

//accessing array field 
//explicit assignment of each index 
struct Month aMonth; 
aMonth.name[0] = 'j';
aMonth.name[1] = 'a';
aMonth.name[2] = 'n';
aMonth.name[3] = '\0';
printf("aMonth name = '%s'\n", aMonth.name);

//initialisation of array field 
struct Month aMonth1 = {30, {'s','e','p','\0'}};
 printf("aMonth1 days: %d ... name = '%s'\n", aMonth1.numDays,aMonth1.name);

//using string and compound literal 
aMonth1 = (struct Month){30, .name="apr"}; 
 printf("aMonth1 days: %d ... name = '%s'\n", aMonth1.numDays,aMonth1.name);

// array of structs representing months of year

struct Month months[12] = 
{
    {31, .name = "Jan"},
    {28, .name = "Feb"},
    {31, .name = "Mar"},
    {30, .name = "Apr"},
    {31, .name = "May"},
    {30, .name = "Jun"},
    {31, .name = "Jul"},
    {31, .name = "Aug"},
    {30, .name = "Sep"},
    {31, .name = "Oct"},
    {30, .name = "Nov"},
    {31, .name = "Dec"}
};
    char suffix[4][3] = 
    {
        {"st"},
        {"nd"},
        {"rd"},
        {"th"} 
    };

    for(int i = 0; i < 12; ++i)
    {
        printf("the %d%s month of the year is %s it has %d days\n", 
        i+1, (i<3)?suffix[i]:suffix[3], months[i].name, months[i].numDays);
    }
    printf("\n");
// Nested structs 
    //create time struct to be used in outer struct 
    struct time 
    {
        int hours;
        int mins; 
    };
    // create outer structure with two structures as fields
    struct dateAndTime
    {
        struct date sdate; //declared at start of prog
        struct time stime; 
    };
    //instantiate and init          set dateTime.sdate     set dateTime.stime
    struct dateAndTime dateTime = {.sdate = {27,12,1989}, .stime = {.hours = 12,.mins = 35}};
    //accessing nested struct field 
    printf("date = %d/%d/%d, time = %d:%d\n", 
    dateTime.sdate.day,dateTime.sdate.month,dateTime.sdate.year,dateTime.stime.hours,dateTime.stime.mins);

//Array of nested structs 
    //init
    struct dateAndTime sdates[3] = 
    {
        {.sdate = {23,2,89}, .stime = {23,23}},
        {},
        {}
    };
    //access 
    printf("sdates[0] date: %d/%d/%d ... time: %d:%d\n\n",
    sdates[0].sdate.day, sdates[0].sdate.month,sdates[0].sdate.year,
    sdates[0].stime.hours,sdates[0].stime.mins);

// nested struct declaration inside the outer struct 

    struct dAndT 
    {
        struct Date //cannot access date struct except through instances of dAndT (it's in the scope of dAndT)
        {
            int day;
            int month;
            int year;

        } dob; // creates instance of struct date called dob in every instance of struct dANdT
        int hours;
        int mins;
        int secs;
    };

    struct dAndT mydob = 
    {
        .dob = {27,12,1989}, //init dob 
        1,30,45 // init hours mins seconds
    };
    

//Pointers to structs 

    struct myStruct 
    {
        struct y 
        {
            int field;
        } Y;

        int fieldOuter;
    };
    // declaration
    struct myStruct X;
    struct myStruct *pX = &X; //pointer to struct X

    //dereferencing 
        //method1 
    (*pX).fieldOuter = 20; 
    (*pX).Y.field = 5; 
    printf("(*pX).fieldOuter = %d ... (*pX).Y.field = %d\n",(*pX).fieldOuter,(*pX).Y.field);
        //method2 
    pX->fieldOuter = 2;
    pX->Y.field = 25; 
    printf("pX->fieldOuter = %d ... pX -> Y.field = %d \n", pX->fieldOuter,pX->Y.field);

// function taking struct as argument 
    struct myName person; 
    struct myName *pperson = &person;
    getinfo(pperson);

    printf("Your first name is: %s \n Yoursurname is: %s\n", pperson->first, pperson->last);

// using type def to simplify struct instantiation 
    struct myComplexStructName
    {
        int field;
    }; 
    typedef struct myComplexStructName mCSN; // creates synonym (mCSN) for "struct myComplexStructName"

    // can declare above struct using much simpler syntax 
    mCSN instance = {20}; 
    printf("instance.field = %d\n", instance.field);


    return 0; 
}
// get info definition - takes a pointer to a struct, prompts user to enter their first and last names, 
// checks the lenght of the entered string and dynamically allocates memory to the character pointer stored as 
//  myName struct field. 
void getinfo(struct myName *ptr)
{
    char temp[BUFFSIZE]; 
    
    printf("Enter your first name: ");
    fgets(temp, BUFFSIZE, stdin);
    temp[strcspn(temp, "\n\r")] = 0; // clear newline 
    ptr->first = (char *)malloc(sizeof(char)*strlen(temp)+1);
    strcpy(ptr->first, temp); 
    
    printf("Enter your second name: "); 
    fgets(temp, BUFFSIZE, stdin);
    temp[strcspn(temp, "\n\r")] = 0; // clear newline     
    ptr->last = (char *)malloc(sizeof(char)*strlen(temp)+1);
    strcpy(ptr->last, temp); 
} 