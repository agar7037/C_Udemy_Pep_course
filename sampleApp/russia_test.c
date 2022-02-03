#include <stdio.h>
#include <locale.h>
#include <wchar.h>
#include <windows.h>



int main(void)
{
    
    //SetConsoleOutputCP(CP_UTF8);
    //SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL,"");
    //wchar_t russian_letter; 
    //wchar_t russian_letter;
    //printf("type a letter: \n");
    //wscanf(L"%lc",&russian_letter);
    //wprintf(L"%lc",russian_letter);
    //scanf("%c", &russian_letter);
     wchar_t rus = 0x0462;
     wchar_t rus1 = L'у';
    //printf("enter a letter: ");
    //scanf("%s", rus);
    wprintf(L"%lc",rus1);
    

}
