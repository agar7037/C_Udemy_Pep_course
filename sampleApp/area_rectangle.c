#include <stdio.h>
#include <stdlib.h> 

int main(int argc, char *argv[])
{
    char *height =  argv[1]; 
    char *width = argv[2]; 
    char *ptr; 
    double H = strtod(height,NULL); 
    double W = strtod(width, NULL); 
    double P = (H+W) * 2;
    double A = (H*W); 

    printf("Height of rectangle: %lf\n",H);
    printf("Width of rectangle: %lf\n", W);
    printf("Perimeter rectange: %lf\n", P);
    printf("Area: %lf\n", A);

    return 0; 
}
