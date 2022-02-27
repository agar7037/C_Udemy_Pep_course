#include <stdio.h>
#include <string.h>

#define BUFFERSIZE 300

int main(void)
{
// file open and read 
    int fseekcheck; 
    char *check = NULL;
    int closeCheck; 
    char buffer[BUFFERSIZE];
    char *pbuf = buffer;
    FILE *pfile = fopen("testPlainText.txt", "r"); 
    int endF = 0;
    if(pfile == NULL)
    {
        printf("file failed to open");
        return(-1);
    }
//printf the first line 
    check = fgets(buffer, BUFFERSIZE, pfile);
    endF = feof(pfile);
    printf("%s",buffer);
// subsequent call prints the second line 
    check = fgets(buffer, BUFFERSIZE, pfile);
    printf("%s",buffer);

    closeCheck = fclose(pfile);
    if(closeCheck < 0)
    {
        printf("file did not close");
        return(-1);
    }
    pfile = NULL;
// fscanf - formatted read grab first three words 
    pfile = fopen("testPlainText.txt", "r");
    char str1[10], str2[10], str3[10];
    fscanf(pfile, "%s %s %s", str1,str2,str3); 
    printf("%s %s %s\n",str1,str2,str3);
    //subsequent call grabs the next three words 
    fscanf(pfile, "%s %s %s", str1,str2,str3); 
    printf("%s %s %s\n",str1,str2,str3);
    fclose(pfile); 
//----------------------------------------open new file ----------------------------------
//writing chars to file 
    pfile = fopen("newTextFile.txt","w+"); 
    if(pfile == NULL)
        {
            printf("file failed to open");
            return(-1); 
        }
    fputc('a', pfile); 
    fputc('\n',pfile);
    rewind(pfile);
    check = fgets(buffer, BUFFERSIZE, pfile);
    endF = feof(pfile);
    printf("%s",buffer);

//fputs - write a string to specified file
// since we wrote a newline to first line of file new string will be on
// line two  
    fputs("string written to output\n", pfile);
//-----------------------------start of file ---------------------------------------------------------
    rewind(pfile);
    check = fgets(buffer, BUFFERSIZE, pfile);// buffer contains a - offset = 27
    long pos = ftell(pfile); // why is this still 2? 
    printf("%s", buffer); // print a 
    check = fgets(buffer, BUFFERSIZE, pfile); // buffer contians "string...." off set still 27 because EOF? eof indicator
    check = fgets(buffer, BUFFERSIZE, pfile); // check = Null
    endF = feof(pfile); // = 1
    
    clearerr(pfile); // reset eof flag 

    fprintf(pfile, "%s %d %s %c", "print", 3, "things", '\n');
    fflush(pfile); // flush to output stream before next fgets call 
    endF = feof(pfile); // now = 0 after clearerr

    int fseekCHeck = fseek(pfile, pos,SEEK_SET); // navigate to 2


    printf("%s", buffer);
    check = fgets(buffer, BUFFERSIZE, pfile);

// fprintf(stream, "%format specifiers", "str1","str2" etc.) write formatted output to file 
// if success return number of successful outputs else return negative number 

    check = fgets(buffer, BUFFERSIZE, pfile);
    printf("%s", buffer);
 
// how long is the file
    int fpos;
    rewind(pfile);
    fseek(pfile,0,SEEK_END); 
    fpos = ftell(pfile); //fpos holds length of file in bytes
    printf("%d\n",fpos);
    


    fseekCHeck = fclose(pfile);

    pfile = NULL;
// navigate to bottom of file write a new line, navigate back to the second line print contents from new line
    pfile = fopen("testPlainText.txt", "r+");
    check = fgets(buffer,BUFFERSIZE, pfile);
    fpos = ftell(pfile); 
    check = fgets(buffer,BUFFERSIZE, pfile);
    check = fgets(buffer,BUFFERSIZE, pfile);
// navigate back to second line and print 
    fseek(pfile, fpos,SEEK_SET); 
    check = fgets(buffer,BUFFERSIZE, pfile);
    printf("%s",buffer); // last line printed should be line two of carl sagan
    closeCheck = fclose(pfile); 
    if(closeCheck != 0)
    {
        printf("file close on line 113 failed");
        return -1; 
    }
    pfile = NULL;
// fset position 

    pfile = fopen("testPlainText.txt", "r+"); 
    fpos_t here; 
    fgetpos(pfile, &here);// record poitner to the head of the file  
    fgets(buffer,BUFFERSIZE,pfile); //navigate to second line
    fgets(buffer,BUFFERSIZE,pfile); // nav to third line 
    fgets(buffer,BUFFERSIZE,pfile); // nav to 4th line 
    printf("%s",buffer); // Should printf the 3rd line 
    fsetpos(pfile, &here); // navigate back to first line 
    fgets(buffer,BUFFERSIZE, pfile); // pointer should be the second line 
    printf("%s", buffer); //should print the first line 
// set pointer to 
    fgetpos(pfile, &here); //record pointer to middle line 
    fgets(buffer,BUFFERSIZE, pfile);// third line - buffer holds 2nd
    fgets(buffer,BUFFERSIZE, pfile);// 4th line - buffer holds third
    fgets(buffer,BUFFERSIZE, pfile);// 5th line - buffer holds 4th 
    fgets(buffer,BUFFERSIZE, pfile);// 6th line - buffer holds 5th 
    fsetpos(pfile, &here); //navigate back to second line 
    fgets(buffer,BUFFERSIZE, pfile);// put 2nd line into buffer
    printf("%s", buffer); //should print the second line 

    printf("\n\n");
    fseekcheck = fclose(pfile); 
    if(fseekcheck != 0)
    {
        printf("file failed to close"); 
        return -1; 
    }
    pfile = NULL;
// what happens when you append and read at the same time 
    
    pfile = fopen("newTextFile.txt", "a+");
    if(pfile == NULL)
    {
        printf("file failed to open "); 
        return -1; 
    }
    rewind(pfile);
    fgets(buffer,BUFFERSIZE, pfile);// 1st line in buffer
    fgets(buffer,BUFFERSIZE, pfile);
    fgetpos(pfile, &here); // save position to return after write to end operation 
    printf("%s", buffer); //printf 1st line 
    fputs("Put this at the end\n", pfile);
    fsetpos(pfile, &here); //return to saved postion after write operation 
    fgets(buffer, BUFFERSIZE, pfile); //2nd line should be in buffer 
    printf("%s", buffer); // printf the second line 
    endF = feof(pfile);

// write first five lines of one file to the other 

    FILE *pfile1 = fopen("testPlainText.txt", "r");
    for(int i = 0; i < 6; ++i)
    {
        fgets(buffer, BUFFERSIZE, pfile1); 
        fputs(buffer, pfile); 
    }



    


    fclose(pfile); 
    fclose(pfile1);
    pfile = NULL;
    pfile1 = NULL;
    return 0; 



}

