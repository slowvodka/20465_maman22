#include "mymat.h"

void mat_print(mat array);
int getCommand(char *str_arr);
int validMatrixName(char * s);
int validOperation(char * s);



int main()
{
    /* define */
    int command_len,i,j,count=0;
    mat F_MAT={}, E_MAT={}, D_MA={}, C_MAT={}, B_MAT={}, A_M={};
    char * my_command,*token;
    char delim1[] = " ",delim2[] = ", ";
    my_command = (char*) malloc(sizeof( char ));

    int flag=0;
    char oper[MAX_COMMAND]={};

    /*do*/
/**/


    while (strcmp(my_command,"stop") != 0)
    {

        command_len = getCommand(my_command);
        command_len = cleanString(my_command,command_len);

        token = strtok(my_command, delim1);
        strcpy(oper, my_command);
        if(validOperation(oper)==0)
            continue;


        printf("%s",oper);
        while (token != NULL)
            token = strtok(NULL, delim2);









        //printf("\n%s", my_command);
        printf("\n");
    }
    free(my_command);
/**/



    // from here it is only tests

    printf("tests\n");

    char bla[] = "read_mat MAT_C, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16" ;

    //printf("%2.2f ",arr[i]);

    for(i=0;i<MAT_SIZE;i++)
        for(j=0;j<MAT_SIZE;j++)
        {
            F_MAT.matrix[i][j] = i;
            E_MAT.matrix[i][j] = 0;
        }

    //mat_print(F_MAT);
    //mat_print(E_MAT);
    //D_MA = mat_add(F_MAT , E_MAT, D_MA);
    //D_MA = mat_sub(F_MAT , E_MAT, D_MA);
    //D_MA = mat_mul(F_MAT , E_MAT, D_MA);
    //D_MA = scalar_mul(F_MAT , 10, D_MA);
    //D_MA = mat_trans(F_MAT , E_MAT);
    //mat_print(D_MA);
}

void mat_print(mat array)
{
    int size = MAT_SIZE,i,j;
    for(i=0;i<size; i++)
    {
        for (j = 0; j < size; j++)
            printf("%7.2f", array.matrix[i][j]);
        printf("\n");
    }
    printf("\n");
}

int getCommand(char *str_arr)
{
    /**
     * function that get a char array from user, dynamic memory
     * @param str_arr - char pointer that will store our array
     * @return - int, array size after input
     */
    int end = EOF;
    int i = 0;
    int current_size = 1;

    printf("\nPlease enter a valid command:");

    if(str_arr != NULL)
    {

        /*accept user input until hit enter or end of file*/
        while ((end = getchar()) != '\n' && end != EOF)
        {
            str_arr[i++] = (char) end;

            /*if i reached maximize size then realloc size*/
            if (i == current_size)
            {
                current_size = i + 1;
                str_arr = realloc(str_arr, current_size);
            }
        }
        str_arr[i] = '\0';

    }
    printf("your input was: %s\n", str_arr);
    return current_size;
}

int validOperation(char * s)
{
    int valid = 0, found = 0 ;
    if(strcmp(s,"mat_add")==0 )
    {
        valid = 1, found = 1;
    }
    if(found == 1 || strcmp(s,"mat_sub")==0)
    {
        valid = 1, found = 1;
    }
    if(found == 1 || strcmp(s,"mat_mul")==0)
    {
        valid = 1, found = 1;
    }
    if(found == 1 || strcmp(s,"scalar_mul")==0)
    {
        valid = 1, found = 1;
    }
    if(found == 1 || strcmp(s,"mat_trans")==0)
    {
        valid = 1, found = 1;
    }
    if(found == 1 || strcmp(s,"stop")==0)
    {
        valid = 1, found = 1;
    }
    if(found == 1 || strcmp(s,"print_mat")==0)
    {
        valid = 1, found = 1;
    }
    if(found == 1 || strcmp(s,"read_mat")==0)
    {
        valid = 1, found = 1;
    }

    if( valid == 0 )
        printf("\nUndefined command name\n");
    return valid;
}

int validMatrixName(char * s)
{
    int valid = 0, found = 0 ;

    if(strcmp(s,"F_MAT")==0 )
    {
        valid = 1, found = 1;
    }
    if(found == 1 || strcmp(s,"E_MAT")==0)
    {
        valid = 1, found = 1;
    }
    if(found == 1 || strcmp(s,"D_MAT")==0)
    {
        valid = 1, found = 1;
    }
    if(found == 1 || strcmp(s,"C_MAT")==0)
    {
        valid = 1, found = 1;
    }
    if(found == 1 || strcmp(s,"B_MAT")==0)
    {
        valid = 1, found = 1;
    }
    if(found == 1 || strcmp(s,"A_M")==0)
    {
        valid = 1, found = 1;
    }

    if( valid == 0 )
        printf("\nUndefined matrix name\n");
    return valid;
}