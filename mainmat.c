#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mymat.h"
#include "io_utils.h"

int flag;
point_mat matrix_array[6];

int readMatMod();
int matPrintCmd();
int matAddCmd();
int matSubCmd();
int matMulCmd();
int matMulScalar();
int matTranspose();
int StopCmd();
int otherError();

int getMatNumber(char *);
int getMat();

int main()
{
    int i,j, func_num;
    char *buffer = NULL;
    char *functionNames[8] = {"read_mat", "print_mat", "add_mat", "sub_mat", "mul_mat", "mul_scalar", "trans_mat", "stop"};
    int (*funcs[9])() = {readMatMod, matPrintCmd, matAddCmd, matSubCmd, matMulCmd, matMulScalar, matTranspose, StopCmd, otherError};

    /*create all mat*/
    for(i= 0; i < 6; i++)
    {
        matrix_array[i] = matCreate();
        if(!matrix_array[i])
        {
            errorHandler(98, "main");
            for(j=0;j<i; j++)
            {
                matDelete(matrix_array[j]);
            }
            return 0;
        }
    }

    flag = TRUE;
    while(flag == TRUE)
    {
        printf("please enter a command: ");
        buffer = getCommand();
        if(buffer)/*clean spaces */
        {
            func_num = 8;
            for(i = 0;i<8;i++)
            {
                if(strcmp(buffer, functionNames[i]) == 0)
                {
                    func_num = i;
                }
            }
            if(funcs[func_num]())/*if was an error in one function, so check EOF*/
            {
                if(checkIfEnd() == 1)
                {
                    errorHandler(1, "main");
                    flag = StopCmd();

                }
                else
                {
                    isThisTheEnd();
                }

            }
            free(buffer);
        }
        else/*checks if the end is \n or EOF*/
        {
            if(checkIfEnd())
            {
                errorHandler(1, "main");
                flag = StopCmd();
            }else{
                errorHandler(2, "main");
                isThisTheEnd();
            }
        }
        printf("\n");
    }
    return 0;
}

int getMatNumber(char *mat_name)
{
    /**
     * from mat name get mat number defined
     * @param mat_name - char* mat name
     * @return int - mat number
     */
    int i = 0;
    char *mat_names[6] = {"MAT_A", "MAT_B", "MAT_C", "MAT_D", "MAT_E", "MAT_F"};
    for(i = 0;i<6;i++)
    {
        if(strcmp(mat_names[i],mat_name) == 0)
            return i;
    }
    return -1;
}

int getMat()
{
    /**
     * get mat number from command
     * @return mat number
     */
    char *buffer = NULL;
    int mat_num;
    buffer = getCommand();
    if(buffer)
    {
        if((mat_num = getMatNumber(buffer)) != -1)
        {
            return mat_num;
        }
        else
        {
            errorHandler(3, "getMat");
            return -1;
        }

    }
    else
    {
        free(buffer);
        errorHandler(4, "getMat");
        return -1;
    }
}

int readMatMod()
{
    /**
     * read_mat wrapper to work with the line
     */
    int i = 0,status;
    int p1;
    double arr[MAT_SIZE*MAT_SIZE], *next;
    next = NULL;
    if((p1 = getMat()) != -1)
    {
        while(commaFind() && i<MAT_SIZE*MAT_SIZE)
        {
            if((next = getNumber()))
            {
                arr[i] = *next;
                i++;
                free(next);
            }
            else
            {
                errorHandler(5, "readMatMod");
                return 1;
            }
        }
        status = isThisTheEnd();
        if(i >= MAT_SIZE*MAT_SIZE || status)
        {
            read_mat(matrix_array[p1], arr,i);
        }
        else
        {
            errorHandler(6, "readMatMod");
        }
    }
    else
    {
        return 1;
    }
    return 0;
}

int matPrintCmd()
{
    /**
     * print_mat wrapper to work with the line
     */
    int p1;
    if((p1 = getMat()) != -1)
    {
        if(isThisTheEnd())
        {
            print_mat(matrix_array[p1]);
        }
        else
        {
            errorHandler(6, "matPrintCmd");
        }
    }
    else
    {
        return 1;
    }
    return 0;
}

int matAddCmd()
{
    /**
   * add_mat wrapper to work with the line
   */
    int p1, p2, p3;
    if((p1 = getMat()) != -1)
    {
        if(commaFind() && (p2 = getMat()) != -1 && commaFind())
        {
            if((p3=getMat()) != -1)
            {
                if(isThisTheEnd())
                {
                    add_mat(matrix_array[p1],matrix_array[p2],&matrix_array[p3]);
                }
                else
                {
                    errorHandler(6, "matAddCmd");
                }
            }
            else { return 1;}
        }
        else
        {
            errorHandler(7, "matAddCmd");
            return 1;
        }
    }
    else { return 1;}
    return 0;
}

int matSubCmd()
{
    /**
    * sub_mat wrapper to work with the line
    */
    int p1, p2, p3;
    if((p1 = getMat()) != -1)
    {
        if(commaFind() && (p2 = getMat()) != -1 && commaFind())
        {
            if((p3=getMat()) != -1)
            {
                if(isThisTheEnd())
                {
                    sub_mat(matrix_array[p1],matrix_array[p2],&matrix_array[p3]);
                }
                else
                {
                    errorHandler(6, "matSubCmd");
                }
            }
            else { return 1;}
        }
        else
        {
            errorHandler(7, "matSubCmd");
            return 1;
        }
    }
    else { return 1;}
    return 0;
}

int matMulCmd()
{
    /**
    * mul_mat wrapper to work with the line
    */
    int p1, p2, p3;
    if((p1 = getMat()) != -1)
    {
        if(commaFind() && (p2 = getMat()) != -1 && commaFind())
        {
            if((p3 = getMat()) != -1)
            {
                if(isThisTheEnd())
                {
                    mul_mat(matrix_array[p1],matrix_array[p2],&matrix_array[p3]);
                }
                else
                {
                    errorHandler(6, "matMulCmd");
                }
            }
            else { return 1;}
        }
        else
        {
            errorHandler(7, "matMulCmd");
            return 1;
        }
    }
    else { return 1;}
    return 0;
}

int matMulScalar()
{
    /**
    * mul_scalar wrapper to work with the line
    */
    int p1, p2;
    double *next= NULL;
    if((p1 = getMat()) != -1)
    {
        if(commaFind())
        {
            if((next = getNumber()))
            {
                if(commaFind())
                {
                    if((p2 = getMat()) != -1)
                    {
                        if(isThisTheEnd())
                        {
                            mul_scalar(matrix_array[p1], *next,&matrix_array[p2]);
                        }
                        else
                        {
                            errorHandler(6, "matMulScalar");
                        }
                    }
                    else { free(next); return 1;}
                }
                else
                {
                    errorHandler(7, "matMulScalar");
                    free(next);
                    return 1;
                }
                free(next);
            }
            else
            {
                errorHandler(8, "matMulScalar");
                return 1;
            }
        }
        else
        {
            errorHandler(7, "matMulScalar");
            return 1;
        }
    }
    else { return 1;}
    return 0;
}
int matTranspose()
{
    /**
     * trans_mat wrapper to work with the line
     */
    int p1, p2;
    if((p1 = getMat()) != -1)
    {
        if(commaFind())
        {

            if((p2 = getMat()) != -1)
            {
                if(isThisTheEnd())
                {
                    trans_mat(matrix_array[p1], &matrix_array[p2]);
                }
                else
                {
                    errorHandler(6, "matTranspose");
                }
            }
            else { return 1;}
        }
        else
        {
            errorHandler(9, "matTranspose");
            return 1;
        }
    }
    else { return 1;}
    return 0;
}

int StopCmd()
{
    /**
     * command to stop + delete
     */
    int i;
    for(i = 0;i<6;i++)
    {
        matDelete(matrix_array[i]);
    }
    flag = FALSE;
    isThisTheEnd();
    return flag;
}

int otherError()
{
    /**
     * non defined error handler
     */
    errorHandler(99, "otherError");
    isThisTheEnd();
    return 0;
}
