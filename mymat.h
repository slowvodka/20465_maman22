#define MAT_SIZE 4

#define FALSE 0
#define TRUE 1

typedef struct mat
{
    double **position;
}mat;

typedef struct mat * point_mat;

point_mat matCreate();
void matDelete(point_mat);

void read_mat(point_mat, double *, int);
void print_mat(point_mat);
void add_mat(point_mat,point_mat,point_mat *);
void sub_mat(point_mat,point_mat,point_mat *);
void mul_mat(point_mat,point_mat,point_mat *);
void mul_scalar(point_mat,double,point_mat *);
void trans_mat(point_mat,point_mat *);