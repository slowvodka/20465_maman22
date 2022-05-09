#include "mymat.h"

struct mat mat_add(mat A , mat B, mat C)
{
    /**
     * function that adds mats
     * @param A - mat, first mat to add
     * @param B - mat, second mat to add
     * @param C - mat, the sum of the two mats
     */
    mat new_mat ={};
    int i,j;
    for(i=0;i<MAT_SIZE; i++)
        for (j = 0; j < MAT_SIZE; j++)
            new_mat.matrix[i][j] = A.matrix[i][j] + B.matrix[i][j];

    C = new_mat;
    return C;
}

struct mat mat_sub(mat A , mat B, mat C)
{
    /**
     * function that substruct mats
     * @param A - mat, first mat to substract from
     * @param B - mat, second mat to be substracted
     * @param C - mat, the difference between the two mats
     */
    mat new_mat ={};
    int i,j;
    for(i=0;i<MAT_SIZE; i++)
        for (j = 0; j < MAT_SIZE; j++)
            new_mat.matrix[i][j] = A.matrix[i][j] - B.matrix[i][j];
    C = new_mat;
    return C;
}

struct mat mat_mul(mat A , mat B, mat C)
{
    /**
     * function that multiplies mats
     * @param A - mat, first mat to mult
     * @param B - mat, second mat to be mult
     * @param C - mat, the multiplication of the two mats
     */
    mat new_mat ={};
    int i,j;
    for(i=0;i<MAT_SIZE; i++)
        for (j = 0; j < MAT_SIZE; j++)
            new_mat.matrix[i][j] = A.matrix[i][j] * B.matrix[i][j];
    C = new_mat;
    return C;
}

struct mat scalar_mul(mat A, float num, mat C)
{
    /**
     * function that multiplies a mat with scalar
     * @param A - mat, mat to mult
     * @param num - mat, real number
     * @param C - mat, the multiplication result
     */
    mat new_mat ={};
    int i,j;
    for(i=0;i<MAT_SIZE; i++)
        for (j = 0; j < MAT_SIZE; j++)
            new_mat.matrix[i][j] = A.matrix[i][j] * num;
    C = new_mat;
    return C;
}

struct mat mat_trans(mat A, mat C)
{
    /**
     * function that transposes a mat
     * @param A - mat, mat to transpose
     * @param C - mat, the transposed mat
     */
    mat new_mat ={};
    int i,j;
    for(i=0;i<MAT_SIZE; i++)
        for (j = 0; j < MAT_SIZE; j++)
            new_mat.matrix[i][j] = A.matrix[j][i];
    C = new_mat;
    return C;
}