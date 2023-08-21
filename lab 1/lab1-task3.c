#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    time_t t;
    srand((unsigned) time(&t));
    
    int m, n, p;
    m = atoi(argv[1]); n= atoi(argv[2]), p= atoi(argv[3]);
    
    int matA[m][n], matB[n][p], matmul[m][p];
    for (int i = 0; i<m; i++){
        for (int j = 0; j<n; j++){
            matA[i][j] = rand() % 10;
        }
    }
    for (int i = 0; i<n; i++){
        for (int j = 0; j<p; j++){
            matB[i][j] = rand() % 10;
        }
    }
    
    for (int i = 0; i<m; i++){
        for (int j = 0; j<n; j++){
            printf("%d ",matA[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");
    for (int i = 0; i<n; i++){
        for (int j = 0; j<p; j++){
            printf("%d ",matB[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");
    for (int i = 0; i<m; i++){
        for (int j = 0; j<p; j++){
            matmul[i][j] = 0;
            for (int k = 0; k < n; k++){
                matmul[i][j] += matA[i][k]*matB[k][j];
            }
        }
    }
    for (int i = 0; i<m; i++){
        for (int j = 0; j<p; j++){
            printf("%d ",matmul[i][j]);
        }
        printf("\n");
    }

}
