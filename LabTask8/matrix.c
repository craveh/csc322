#include <stdio.h>

void multiply(int m1, int m2, int mat1[][m2], int n1,
              int n2, int mat2[][n2])
{
    //create new matrix
    if(n1 != m2){
        printf("These matrices cannot be multiplied. The num columns of mat1 doesn't equal the num rows of mat2");
        return;
    }

    //int rows = m1;
    //int cols = n2;
    int multMatrix[m1][n2];
    //int *pointer = &multMatrix[0];
    //int *pointCol = &multMatrix[][0];

    for(int i=0; i<m1; i++){
        for(int j=0; j<n2; j++){
            *(*(multMatrix + i) + j) = 0;
        }
    }



    //fill out the matrix
    for(int i =0; i<m1; i++){
        for(int j=0; j<n2; j++){
            for(int k=0; k<n1; k++){

                *(*(multMatrix + i) + j) += *(*(mat1+i) + k) * (*(*(mat2 + k) + j));

            }
        }
    }




    //printout results
    for(int i=0; i<m1; i++){
        for(int j=0; j<n2; j++){
            printf("%d ", *(*(multMatrix+i)+ j) );
        }
        printf("\n");
    }





}

// Driver code
int main()
{
    int mat1[][2] = { { 2, 4 }, { 3, 4 } };
    int mat2[][2] = { { 1, 2 }, { 1, 3 } };
    int m1 = 2, m2 = 2, n1 = 2, n2 = 2;



    // Function call
    multiply(m1, m2, mat1, n1, n2, mat2);
    return 0;
}
