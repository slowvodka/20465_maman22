#include "io_utils.h"

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


char temp[BUFFER];
static int index = -1;

char getNext()
{
    if(index>-1)
    {
        return temp[index--];
    }
    return getchar();
}

void setNext(char c)
{
    temp[++index] = c;
}

double *getNumber()
{
    /**
     * function to determine if is a number
     * @return double
     */
    double *num = NULL;
    char c;
    int sign = 1;
    int i = 0;
    char *buf = (char *)calloc(BUFFER,sizeof(char));
    if(buf)
    {
        num = (double *)malloc(sizeof(double));
        if(num)
        {
            getRidofThisSpace();
            c = getNext();
            if(c == EOF || c == '\n')
            {
                errorHandler(6, "getNumber");
                temp[++index] = c;
                free(buf);
                free(num);
                return NULL;
            }
            if(c == '-')/*for negative numbers*/
            {
                buf[i] = c;
                i++;
                c = getNext();
            }
            do
            {
                if(c >= '0' && c <= '9')/*is char*/
                {
                    buf[i] = c;
                    i++;
                }
                else if(sign && c == '.')
                {
                    buf[i] = c;
                    i++;
                    sign = 0;
                }else{
                    temp[++index] = c;
                    errorHandler(6, "getNumber");

                    free(buf);
                    free(num);
                    return NULL;
                }
            }while((c=getNext()) != EOF && !isspace(c) && i<=BUFFER && c != ',');
            temp[++index] = c;
            *num = atof(buf);
            free(buf);
        }else{ errorHandler(10, "getNumber");}
    }else{ errorHandler(10, "getNumber");}
    return num;
}

char *getCommand()
{
    char *buffer = NULL;
    char c;
    int i = -1;
    getRidofThisSpace();
    buffer = (char *)calloc(BUFFER,sizeof(char));
    if(buffer)
    {
        while((c = getNext()) != EOF && !isspace(c) && i < BUFFER  && c != ',')
        {
            i++;
            *(buffer+(i)) = c;
        }
        setNext(c);
        if(i<0)/*if no string*/
        {
            free(buffer);
            return NULL;
        }
    }else
    {  return NULL; }

    return buffer;
}
int checkIfEnd()
{
    /**
     * check if end
     * @return 1 yes 0 no
     */
    char c = getNext();
    temp[++index] = c;
    if(c == EOF)
        return 1;
    else
        return 0;
}
int commaFind()
{
    /**
     * function look for ',' and jump over it,
     * @return 1 if founded, 0 if not
     */
    char c;
    getRidofThisSpace();
    c = getNext();
    if(c == ',')
    {
        return 1;
    }
    else
    {
        temp[++index] = c;
        return 0;
    }
}
int isThisTheEnd()
{
    /**
     * if until end of command there is a char that is not space
     * @return 1 True 0 False
     */
    char c;
    int back = 1;
    while((c=getNext()) != EOF && c != '\n')
    {
        if(!isspace(c))
            back = 0;
    }
    if(c == EOF)
    {
        temp[++index] = c;
    }
    return back;
}
void getRidofThisSpace()
{
    /**
     * function to get rid of spaces
     */
    char c;
    while((c = getNext()) != EOF && isspace(c) && c != '\n');
    temp[++index] = c;
}

void errorHandler(int error_num, char * function_name)
{
    /**
     * function to print the relevant error with the relevant name (for debugging purpuses)
     * @param error_num
     * @param function_name
     *
     */
    switch (error_num) {
        case 1:
            printf("Error: Unexpected end of program. Occurred in %s\n", function_name);
        case 2:
            printf("Error: Expected next function name. Occurred in %s\n", function_name);
        case 3:
            printf("Error: One or more of matrix name was undefined. Occurred in %s\n", function_name);
        case 4:
            printf("Error: Undefined matrix name. Occurred in %s\n", function_name);
        case 5:
            printf("Error: Expected number after ','. Occurred in %s\n", function_name);
        case 6:
            printf("Error: Extraneous text after end of command. Occurred in %s\n", function_name);
        case 7:
            printf("Error: Missing argument. Occurred in %s\n", function_name);
        case 8:
            printf("Error: Argument is not a real number. Occurred in %s\n", function_name);
        case 9:
            printf("Error: Illegal comma. Occurred in %s\n", function_name);
        case 10:
            printf("Error: Unable to read next number. Occurred in %s\n", function_name);



        case 98:
            printf("Error: Memory error. Occurred in %s\n", function_name);
        case 99:
            printf("Error: Undefined command name. Occurred in %s\n", function_name);


    }

}
