//---------------------------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>

typedef int *intPointer;

typedef char *String;

//---------------------------------------------------------------------------
double * input_matrix(intPointer rows, intPointer cols, String name){
    double *matrix;
    int totalNums;
    printf("Enter the number of rows and columns for %s: ", name);
    scanf("%d %d", rows, cols);
    totalNums = (*rows)*(*cols);


    matrix = (double *)malloc(totalNums * sizeof(double));
    double number;
    for (int i = 0; i < totalNums; i++)
    {
        //printf("%d\n", i);
        printf("Enter a number into the matrix: ");
        scanf("%lf", &number);
        matrix[i] = number;
        //printf("%lf  ", matrix[i]);
    }
    printf("\n");



    return matrix;

}
//---------------------------------------------------------------------------
void output_matrix(double *matrix, int rows, int cols){
    int size = rows *cols;
    //printf("\n");
    for(int i=0; i<size; i++){
        if(i%cols == 0){
            printf("\n");
        }
        printf("%.0lf ", matrix[i]);
    }
    printf("\n\n");

}
//---------------------------------------------------------------------------
int matrix_multiply(double *matrix1, int rows1, int cols1, double *matrix2, int rows2, int cols2, double *newMatrix){

    if(cols1 != rows2){
        //printf("Error testing wrong size\n");
        return 0;
    }
    //int matrixSize = rows1*cols2;
    //newMatrix = (double *)malloc(matrixSize*sizeof(double));




    for(int i =0; i<rows1; i++){
        for(int j=0; j<cols2; j++){
            for(int k=0; k<cols1; k++){

                newMatrix[(i*cols2) + j] += matrix1[i*cols1+k] * matrix2[j+k*cols2];

            }
        }
    }

    //output_matrix(newMatrix, rows1, rows2);
    return 1;


}

//---------------------------------------------------------------------------

int main(void) {

    double *m1,*m2,*m3;
    int m1_rows,m1_columns,m2_rows,m2_columns;



    if (((m1 = input_matrix(&m1_rows,&m1_columns,"Matrix 1")) != NULL) &&
((m2 = input_matrix(&m2_rows,&m2_columns,"Matrix 2")) != NULL) &&
((m3 = malloc(m1_rows*m2_columns*sizeof(double))) != NULL)) {
        printf("Matrix 1\n");

        output_matrix(m1,m1_rows,m1_columns);
        printf("Matrix 2\n");
        output_matrix(m2,m2_rows,m2_columns);
        if (matrix_multiply(m1,m1_rows,m1_columns,m2,m2_rows,m2_columns,m3))
{
            printf("Product\n");
            output_matrix(m3,m1_rows,m2_columns);
            free(m1);
            free(m2);
            free(m3);
            return(0);
        } else {
            printf("Error in dimensions\n");
            free(m1);
            free(m2);
            free(m3);
            return(-1);
        }
    } else {
        free(m1);
        free(m2);
        free(m3);
        printf("Error allocating memory\n");
        return(-2);
    }


}
