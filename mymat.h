

#ifndef INC_20465_MAMAN22_MYMAT_H
#define INC_20465_MAMAN22_MYMAT_H
#endif //INC_20465_MAMAN22_MYMAT_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

#define MAT_SIZE 4
#define MAX_COMMAND 100

typedef struct mat {
    float matrix[MAT_SIZE][MAT_SIZE];
} mat;



struct mat mat_add(mat A , mat B, mat C);
struct mat mat_sub(mat A , mat B, mat C);
struct mat mat_mul(mat A , mat B, mat C);
struct mat scalar_mul(mat A, float num, mat C);
struct mat mat_trans(mat A, mat C);