#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define Buffersize 200
struct item
{
    char *itemName;
    int quantity;
    float price; 
    float amount; // quantity*price
};
typedef struct item Item;

void readItem(Item *pItem); 
void printItem(Item *pItem);


int main(void)
{
//Declare item and pointer to item - allocate memory for itemName
Item item1, *pitem = &item1; 
readItem(pitem);
printItem(pitem);

return 0;

}


/*readItem function Declaration
Read from user 
    .product name 
    .price
    .quantity
calculate amount
*/
void readItem(Item *pItem)
{
   char temp[Buffersize];
   int quantity = 0; 
   float price = 0.0f;
   bool input = false;
   // get item name - check for successful input 
   printf("Enter item name: ");
   while(input == false)
   {
        input = fgets(temp, Buffersize, stdin);
        if(input == false)
        {
            printf("fgets returned NULL, Input unsuccesful try again: ");
            continue;
        }
   }
    // strip new line char from fgets, copy into item struct member 
    pItem->itemName = (char*)malloc((strlen(temp)+1)*sizeof(char));
    temp[strcspn(temp,"\n\r")] = 0;
    strcpy(pItem->itemName, temp);
    
    // get item quantity 
    printf("Enter item quantity: "); 
    input = false; 
    while(input == false)
    {
        input = scanf("%d", &quantity);
        while(getchar()!='\n'){}
        if(input == false || quantity < 0)
        {
            printf("Invalid input, quantity must be positive integer: ");
            continue;
        }
    }
    pItem->quantity = quantity;
   
    // get item price 
    input = false; 
    printf("Enter item price ($): ");
    while(input == false)
    {
        input = scanf("%f", &price);
        while(getchar()!='\n');
        if(input == false)
        {
            printf("Invalid input, price must be a float");
            continue;
        }
    }
    pItem->price = price;
    pItem->amount= price*quantity;
}
void printItem(Item *pItem)
{
    printf("\n\n");
    printf("Item name: %s\n", pItem->itemName);
    printf("Quantity: %d\n",pItem->quantity);
    printf("Price: %.3f\n",pItem->price);
    printf("Total value: %.3f\n",pItem->amount);
}