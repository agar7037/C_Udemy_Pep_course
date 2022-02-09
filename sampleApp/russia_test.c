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
    wchar_t* rus1 = L"Але";
    //printf("enter a letter: ");
    //scanf("%s", rus);
    printf("%ls\n",rus1); 

    /*
    Notes on wide string:
        .Must declare a wide string as a pointer 
        .For formating must use long string format specifier %ls or %S, for single widechar use %C and declare with L'wchar_t'
        .Must include both locale and wide string headers 
        .Using printf in conjunction with wprintf creates buffering issues - so basically use one are the other
    Notes on dictionary 
        .C actually allows you to access array elements that don't exist - it does not do bounds checking
        
    */
       //struct declarations - maybe move to config files later
        //struct definitions here 
    struct word {
        wchar_t* Rus;
        char *En;
        wchar_t *Ru_sentence; // maybe change to array of sentences later
        char *En_sentence; 
    }; 
    struct word word1;

        word1.Rus = L"привет"; 
        word1.En = "Hello";
        word1.Ru_sentence = L"Привет, меня зовут Александр.";
        word1.En_sentence = "Hello, my name is Alexander.";

    struct word word2;

        word2.Rus = L"хорошо"; 
        word2.En = "Okay - positive afermation"; 
        word2.Ru_sentence = L"P1: все хорошо? P2: да все хорошо";
        word2.En_sentence = "P1: All good? P2: Yes all good.";

    // dictionary 

    struct word dictionary[2]; 
    dictionary[0] = word1;
    dictionary[1] = word2;
    printf("dictionary entry 1 english: %s\n", dictionary[0].En);
    printf("dictionary entry 1 rus: %ls\n", dictionary[0].Rus);
    printf("dictionary entry 1 rus sentence: %ls\n", dictionary[0].Ru_sentence);
    printf("dictionary entry 1 english sentence: %s\n\n", dictionary[0].En_sentence);

    printf("dictionary entry 2 english: %s\n", dictionary[1].En);
    printf("dictionary entry 2 rus: %ls\n", dictionary[1].Rus);
    printf("dictionary entry 2 rus sentence: %ls\n", dictionary[1].Ru_sentence);
    printf("dictionary entry 2 english sentence: %s\n", dictionary[1].En_sentence);

    printf("dictionary entry 3: \n", dictionary[100].Rus); // should be garbage or throw error
    printf("size of wide char: %zd",sizeof(wchar_t));



}
