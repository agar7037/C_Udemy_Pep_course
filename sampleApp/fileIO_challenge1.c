#include  <stdio.h>
#include  <ctype.h>
#include  <string.h>
#define BUFFERSIZE 200

int lineCount(FILE *pfile, char *buffer); 
int convertUpper(char* filename); 
int convertLower(char* filename);
void printReverse(FILE *pfile);
int countWord(FILE *pfile, const char *word);
int lineCountWord(char *line, const char *word);

int main(void)
{
//-------------------------------------CHALENGE 1---------------------------------------------------------
    char buffer[BUFFERSIZE];  
    char file[] = "testPlainText.txt";
    FILE *pcarlSagan = fopen(file, "r");
    int count = 0; 
    int expected = 26;
    if(pcarlSagan == NULL)
    {
        printf("file /%s failed to open check file path", file);
        return -1; 
    }
    count = lineCount(pcarlSagan, buffer);
    printf("This file has %d lines\n", count); 
    printf("expected %d ... actual %d\n%s", expected, count, (expected == count)?"test pass":"test fail");

    fclose(pcarlSagan);
    pcarlSagan = NULL;

//-----------------------------------------CHALLENGE 2--------------------------------------------------
    char filename[] = "carlSag.txt";
    int converted = convertUpper(filename);
    if(converted != 0)
    {
        printf("failed to convert");
        return -1;
    }

    FILE *pcarl = fopen(filename, "r"); 
    while(fgets(buffer, BUFFERSIZE, pcarl) != NULL)
    {
        printf("%s",buffer); 
    }


    fclose(pcarl);
    pcarl = NULL; 
    
//-----------------------------------------------CHALLENGE 3---------------------------------------------

    pcarl = fopen(filename, "r");
    printReverse(pcarl);
    fclose(pcarl);
    pcarl = NULL;




//--------------------------------------------MY CHALLENGE----------------------------------------------
//count the occurence of a given word in a file 
    printf("\n\n");
    FILE *pand = fopen("testPlainText.txt", "r");
    if(pand == NULL)
    {
        printf("and file did not open check name ");
        return -1; 
    }
    char word[] = "the"; 
    int andCount = countWord(pand, word);
    printf("found %d occurances of and, expected 4\n",andCount);

    fclose(pand);
    pand = NULL;
    return 0; 
}
/*
Counts the number of lines in a file using fgets
    call fgets until reach EOF, increment count each time
*/
int lineCount(FILE *pfile, char *buffer)
{
    int count = 0; 
    while(fgets(buffer, BUFFERSIZE, pfile)!= NULL)
    {
        count += 1; 
    } 
    return count; 
}

/*
Convert characters in file to upper case
    .open file using file name 
    .create and open a file named temp.txt write mode
    .iterate through target file char by char converting to uppercase and writing result to temp
    .when done close target file and delete, 
    .close temp and rename to OG file name
*/
int convertUpper(char* filename)
{
    int converted = 0;
    int writeSuccess;
    FILE *ptargetFile = fopen(filename, "r");
    FILE *ptemp = fopen("temp.txt", "w"); 
    char currentChar; 
    if(ptargetFile == NULL)
    {
        printf("File failed to open inside convertUpper");
        converted = -1;
    }
    while(converted == 0 && (currentChar = fgetc(ptargetFile)) != EOF)
    {
        if(islower(currentChar) != 0)
        {
            currentChar = toupper(currentChar); 
        }
        writeSuccess = fputc(currentChar, ptemp);
        if(writeSuccess == 0)
        {
            printf("conversion failed inside loop");
            converted = -1;
            break;
        }
    }
    if(converted == 0)
    {
        fclose(ptargetFile);
        fclose(ptemp);
        remove(filename);
        rename("temp.txt", filename);
    }
    else
        {
            fclose(ptemp);
            remove("temp.txt");
        }
    return converted; 
} 
int convertLower(char* filename)
{
    int converted = 0;
    int writeSuccess;
    FILE *ptargetFile = fopen(filename, "r");
    FILE *ptemp = fopen("temp.txt", "w"); 
    char currentChar; 
    if(ptargetFile == NULL)
    {
        printf("File failed to open inside convertUpper");
        converted = -1;
    }
    while(converted == 0 && (currentChar = fgetc(ptargetFile)) != EOF)
    {
        if(isupper(currentChar) != 0)
        {
            currentChar = tolower(currentChar); 
        }
        writeSuccess = fputc(currentChar, ptemp);
        if(writeSuccess == 0)
        {
            printf("conversion failed inside loop");
            converted = -1;
            break;
        }
    }
    if(converted == 0)
    {
        fclose(ptargetFile);
        fclose(ptemp);
        remove(filename);
        rename("temp.txt", filename);
    }
    else
        {
            fclose(ptemp);
            remove("temp.txt");
        }
    return converted; 
} 

/*
print file in reverse 
    .navigate to the end of the file
    .store end of file pos with ftell call
    .loop through file printing chars and decrementing file pos until start 
*/
void printReverse(FILE *pfile)
{
    char currentCharacter; 
    long count; 
    fseek(pfile, 0, SEEK_END);
    count = ftell(pfile);
    count -= 1; 
    while(count >= 0)
    {
        fseek(pfile,count,SEEK_SET);
        currentCharacter = fgetc(pfile); 
        printf("%c",currentCharacter);
        count -= 1;
    }
}

/*
Search through file count the occurence of word
    .open file 
    .check file line by line 
    .on each line use line countword to count number of instacnes of word 
    .continue until end of file 
*/
    int countWord(FILE *pfile, const char *word)
    {
        char buffer[BUFFERSIZE];
        int count = 0;  
        while(fgets(buffer, BUFFERSIZE, pfile) != NULL)
        {
            count += lineCountWord(buffer, word);
        }
        return count; 
    }
/*
    to be used 

*/
/*
.set count to 0, use strstr to advance to first instance of word
.increment pointer
.repeat search until null byte 
*/
    int lineCountWord(char *line, const char *word)
    {
        int count = 0;
        char *token; 
        char delim[] = " ";
        int wordFound;
        token = strtok(line, delim);
        while(token != NULL)
        {
            wordFound = strcmp(token, word);
            if(wordFound == 0)
            {
                count += 1;
            }
            token = strtok(NULL, delim);
        }
        return count; 
    }
