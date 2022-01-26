#include <stdio.h>

int main()
{
    float val1, val2; 
    char operator;
    printf("type in your expression.\n");
    scanf("%f %c %f", &val1, &operator,&val2);

    switch (operator)
    {
        case '+':
            printf("%.2f\n",val2+val1);
            break;
        case '/':
            if (val2 == 0)
            {
                printf("divide by zero error\n");
            }
            else 
                printf("%.2f\n",val1/val2);
            break;
        case '*':
            break;
        case '-':
            printf("%.2f",val1-val2);
            break;
        default: 
            printf("Unkown operator \n");
            break;
    }

    return 0;
}