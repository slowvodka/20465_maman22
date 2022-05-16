#include "mymat.h"
#include "io_utils.h"

#include <stdio.h>
#include <stdlib.h>


static void setInMat(point_mat p,int i, int j,double number)
{
    /**
     * setter
     * @param p - matrix
     * @param i - row
     * @param j - col
     * @param number - the number to be setted
     */
    *(*((p->position)+i)+j) = number;
}
static double getFromMat(point_mat p,int i, int j)
{
    /**
     * getter
     * @param p - matrix
     * @param i - row
     * @param j - col
     * @return double - p[i][j]
     */
    return *(*((p->position)+i)+j);
}


point_mat matCreate()
{
    /**
     * mat creator and initiator
     * @return pointer to mat
     */
    point_mat new_point_mat;
    int i,j;
    new_point_mat = (point_mat)malloc(sizeof(mat));
    if(new_point_mat)
    {
        new_point_mat->position = (double **)malloc(MAT_SIZE*(sizeof(double *)));
        if(new_point_mat->position)
        {
            for(i=0; i<MAT_SIZE; i++)
            {
                *((new_point_mat->position)+i) = (double *)malloc(MAT_SIZE*(sizeof(double)));
                if(!(*((new_point_mat->position)+i)))/*case one of malloc didn't success*/
                {
                    for(j = 0;j<=i;j++)
                    {
                        free(*((new_point_mat->position)+j));
                    }
                    return NULL;
                }
            }
        }else{
            free(new_point_mat);
            return NULL;
        }
    }else{
        return NULL;
    }
    return new_point_mat;
}

void matDelete(point_mat p)
{
    /**
     * delete matrix
     * @param p - pointer to matrix
     */
    int i;
    for(i=0;i<MAT_SIZE;i+=1)
    {
        free(*((p->position)+i));
    }
    free(p);
}

void read_mat(point_mat p, double *arr, int Last)
{
    /**
    * function that read mat
    * @param p - mat pointer
    * @param arr - double array
    * @param last - last position to place number
    */
    int i,j,k=0;
    for(i = 0;i <MAT_SIZE; i+=1)
    {
        for(j = 0;j<MAT_SIZE; j+=1)
        {
            if(Last >= k)
            {
                setInMat(p,i,j,arr[k]);
                k++;
            }
            else
            {
                setInMat(p,i,j,0);
            }
        }
    }
}

void print_mat(point_mat p)
{
    /**
     * function to print mat
     * @param p - matrix pointer
     */
    int i,j;
    printf("\n");
    for(i=0; i < MAT_SIZE; i++)
    {
        for(j=0; j < MAT_SIZE; j++)
        {
            printf("%10.2f",getFromMat(p,i,j));
            printf((j+1 < MAT_SIZE)? "," : "");
        }
        printf("\n");
    }
}

void add_mat(point_mat p1,point_mat p2,point_mat *p3)
{
    /**
    * function that adds mats
    * @param p1 - mat, first mat to add
    * @param p2 - mat, second mat to add
    * @param p3 - mat, the sum of the two mats
    */
    int i,j;
    double number;

    point_mat new_point_mat = matCreate();
    if(new_point_mat)
    {
        for(i=0; i < MAT_SIZE; i++)
        {
            for(j=0; j < MAT_SIZE; j++)
            {
                number = getFromMat(p1,i,j) + getFromMat(p2,i,j);
                setInMat(new_point_mat,i,j,number);
            }
        }
        matDelete(*p3);
        *p3 = new_point_mat;

    }
    else
    {
        errorHandler(98, "add_mat");
    }
}

void sub_mat(point_mat p1,point_mat p2,point_mat *p3)
{
    /**
    * function that substracts mats
    * @param p1 - mat, first mat
    * @param p2 - mat, second mat to be substracted
    * @param p3 - mat, the diff of the two mats
    */
    int i,j;
    double number;
    point_mat new_point_mat = matCreate();
    if(new_point_mat)
    {
        for(i=0; i < MAT_SIZE; i++)
        {
            for(j=0; j < MAT_SIZE; j++)
            {
                number = getFromMat(p1,i,j) - getFromMat(p2,i,j);
                setInMat(new_point_mat,i,j,number);
            }
        }
        matDelete(*p3);
        *p3 = new_point_mat;
    }
    else
    {
        errorHandler(98, "sub_mat");
    }
}
void mul_mat(point_mat p1,point_mat p2,point_mat *p3)
{
    /**
    * function that substracts mats
    * @param p1 - mat, first mat
    * @param p2 - mat, second mat
    * @param p3 - mat, the mult of the two mats
    */
    int i,j,k;
    double number;
    point_mat new_point_mat = matCreate();
    if(new_point_mat)
    {
        for(i=0; i < MAT_SIZE; i++)
        {
            for(j=0; j < MAT_SIZE; j++)
            {
                number = 0;
                for(k=0; k < MAT_SIZE; k++)
                {
                    number += getFromMat(p1,i,k) * getFromMat(p2,k,j);
                }
                setInMat(new_point_mat,i,j,number);
            }
        }
        matDelete(*p3);
        *p3 = new_point_mat;
    }
    else
    {
        errorHandler(98, "mul_mat");
    }
}

void mul_scalar(point_mat p1,double num,point_mat *p2)
{
    /**
    * function that substracts mats
    * @param p1 - mat, first mat
    * @param num - real number
    * @param p2 - mat, the mult of the mat and num
    */
    int i,j;
    double number;
    point_mat new_point_mat = matCreate();
    if(new_point_mat)
    {
        for(i=0; i < MAT_SIZE; i++)
        {
            for(j=0; j < MAT_SIZE; j++)
            {
                number = getFromMat(p1,i,j) * num;
                setInMat(new_point_mat,i,j,number);
            }
        }
        matDelete(*p2);
        *p2 = new_point_mat;
    }
    else
    {
        errorHandler(98, "mul_scalar");
    }
}
void trans_mat(point_mat p1,point_mat *p2)
{
    /**
     * transpose mat
     * @param p1 - mat to be transposed
     * @param p2 - transposed mat
     */
    int i,j;
    double number;
    point_mat new_point_mat = matCreate();
    if(new_point_mat)
    {
        for(i=0; i < MAT_SIZE; i++)
        {
            for(j=0; j < MAT_SIZE; j++)
            {
                number = getFromMat(p1,i,j);
                setInMat(new_point_mat,j,i,number);
            }
        }
        matDelete(*p2);
        *p2 = new_point_mat;
    }
    else
    {
        errorHandler(98, "trans_mat");
    }
}