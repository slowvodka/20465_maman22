#include "utils.h"

int cleanString(char *str_arr, int arr_len)
{
    /**
     * helper functions that cleans all spaces and tabs
     * after this all tabs converted spaces
     */
    int i,j;
    char last = ' ';
    for (i=0,j=0; i<arr_len; i++)
    {
        if((str_arr[i] != ' ' & str_arr[i] != '\t') | (last != ' ' & last != '\t'))
        {
            if(str_arr[i] == '\t')
                str_arr[i] = ' ';
            str_arr[j] = str_arr[i];
            j++;
        }
        last = str_arr[i];
    }
    if (j<i)
        str_arr[j+1] = EOF;
    strncpy(str_arr, &str_arr[0],j);
    return j;
}

char *removeSpaces(char *s)
{
    int c=0,j=0;
    while(s[c]!='\0'){
        if(s[c]!=' '){
            s[j++]=s[c];
        }
        c++;
    }
    s[j]='\0';
    return s;
}



