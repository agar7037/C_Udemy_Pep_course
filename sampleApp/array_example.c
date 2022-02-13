#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int array[10];
    int count = sizeof(array)/sizeof(int); // calculate the number of iterations for the loop 
    printf("size of array = %zd\n", sizeof(array)/sizeof(int));
    for(int i = 0; i < count; i++)
    {
        array[i] = i+1;
        printf("array index %d is %d\n", i, array[i]);
    }
    // Try print out of bounds 
    printf("array out of bounds: %d\n", array[5]);
    printf("printing array var: %p\n", array); // array var name is a pointer to the first member of array 
    printf("first element of array: %d\n", *array);// prints the first element of the array 

    // grades calcualtion 
    int grade_code = 0; // change to see grade calc output 
    if (grade_code == 1)
    { 
 
        int grades[10]; 
        float average = 0.0f; 
        int cum_sum = 0; 
        count = sizeof(grades)/sizeof(int);


        printf("enter 10 grades\n");
        for(int i = 0; i < count; i++)
        {
            printf("Grade%d: ",i+1);
            scanf("%d", &grades[i]);
            cum_sum += grades[i];

        }
        average = (float)cum_sum/(float)count;
        printf("Total sum of grades: %d\n", cum_sum);
        printf("Average mark: %.2f", average);
    }
// initialization 
    int initialization = 0; // change to see initialization 
    if (initialization == 1){
        int numbers[100] = {100,200,3}; // initializing first three elements - all the rest are zero 
        for(int i = 0; i < 100; i++)
        {
            printf("%d, ",numbers[i]);
        }
        printf("\n");
        int numbers1[100] = {[50] = 2, [99] = 7}; // initalize the 51st and 100th elements, all other elements are zero 
        for(int i = 0; i < 100; i++)
        {
            printf("%d, ", numbers1[i]);
        }
        int numbers2[100]; 
        printf("\n");
        for(int i = 0; i < 100; i++) // no inital values array filled with randomly (garbage)
        {
            printf("%d, ",numbers2[i]);  
        }
        int numbers3[100] = {0}; // fills entire array with zeros 
        printf("\n");
        for(int i = 0; i < 100; i++) // no inital values array filled with randomly (garbage)
        {
            printf("%d, ",numbers3[i]);  
        }
    }

// 2 dimensional arrays 
    int twoD = 0;
    if (twoD == 1){
        int multdim[2][2] = {
            {0,1}, // first row ie multdim[0][1] = 1
            {1,2} // 2nd row 
        }; // 2 X 2 matrix 
        for(int m = 0; m<2; m++) // print matrix
        {
            for(int n = 0; n<2;n++)
            {
                printf("%d ", multdim[m][n]);
            }
            printf("\n");
        }
        printf("\n");
    // set the first three elements of each row, all other row elements set to 0 
        int multdim1[4][5] = 
        {
            {1,2,3},//row1 
            {2,1,3},//row2
            {2,3,1},//row3
            {2,4,3} //row4
        }; 
        for(int m = 0; m<4; m++) // print matrix
        {
            for(int n = 0; n<5;n++)
            {
                printf("%d ", multdim1[m][n]);
            }
            printf("\n");
        }
    // create 8 X 8 zero matrix 
        printf("\n"); 
        int multidim2[8][8] = {{0}};
        for(int m = 0; m<8;m++)
        {
            for(int n = 0; n<8;n++)
            {
                printf("%d ",multidim2[m][n]);
            }
            printf("\n");
        }
        // create 8X8 identidy matrix 
        printf("\n");
        int multidim3[8][8] = {{0}};
        for(int m = 0; m<8;m++)
        {
            for(int n = 0; n<8;n++)
            {
                multidim3[m][n] = 1;
                printf("%d ",multidim3[m][n]);
            }
            printf("\n");
        }
        printf("\n");
        // initialized specifi entries of 2D array 
        int multidim4[4][4] = {[0][0] = 1 , [1][1] = 1, [2][2] = 1, [3][3] = 1}; //Diagonal matrix 
        for(int m =0;m<4;m++){
            for(int n = 0; n<4;n++){
                printf("%d ", multidim4[m][n]);
            } 
            printf("\n");
        }
    }
    // 3d & higher 
    // initialize by curly bracket for each mxn matrix 
    /*
        i.e 
        array[3][2][2] = {
            {{1st row},{2nd row}}, 2x2 1 
            {{1st row},{2nd row}}, 2x2 2
            {{1st row},{2nd row}}  2x2 3
            };

    */
    int threeD[2][3][4] = {
        {       //first block of 3 rows (4 colmns)
            {0,0,0,0},
            {0,0,0,0},
            {0,0,0,0}
        },
        {       //second block of 3 rows (4 colmns)
            {1,1,1,1},
            {1,1,1,1},
            {1,1,1,1}
        }
    };
    // printing three D array 
    for(int k=0;k<2;k++){
        for(int m=0;m<3;m++){
            for(int n=0;n<4;n++){
                printf("%d ",threeD[k][m][n]);
            }
            printf("\n");
        }
        printf("\n\n");
    }
    printf("\n");
// variable length array 
 // DYNAMIC METHOD c11 
    int *A = NULL; 
    A = malloc(sizeof(int)*10); 
    for(int i = 0; i<10;i++){
        A[i]=i+2;
        printf("%d, ", A[i]);
    }
    printf("\n");
    printf("length of array: %zd \n", (sizeof(A)/ sizeof(int)));
    A = realloc(A, sizeof(int)*10000); 
    printf("length of array after realloc: %zd\n", sizeof(A)/sizeof(int));
    for(int i = 10 ; i < 20 ; i++){
        A[i] = i+2;
        printf("%d, ",A[i]);
    }
    // not sure if this is an acceptable way to deal with variable length arrays - can no longer do bounds checking from the compiler
    // can just write into out of bounds addresses willie nillie 
    // although this is how they do it on dev docs so I dunno maybe ask anthony 
    A[100] = 57; 
    printf("\n");
    printf("an out of bounds entry %d\n", A[100]);
    printf("A : %p\n", A);
    printf("*A : %d\n", *A); 

// VLA c99 not really variable lenght array, just able to use variables to implement the array 

    int m = 2; 
    int n = 2; 
    int A1[m][n]; // variable length array available in C99 standard, cannot initialize array with values
    for(int i = 0; i <m; i++){
        for(int k = 0; k < n; k++){
            A1[i][k] = 7; 
            printf("%d ", A1[i][k]);
        }
        printf("\n");
    }




    return 0;


}