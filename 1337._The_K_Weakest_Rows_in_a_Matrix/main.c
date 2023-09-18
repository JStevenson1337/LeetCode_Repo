#include <stdio.h>
#include <stdlib.h>

// Custom structure to store the row index and number of soldiers
typedef struct {
    int rowIndex;
    int numSoldiers;
} Row;

// Helper function for comparing two rows based on the number of soldiers
int compare(const void *a, const void *b) {
    Row *rowA = (Row *)a;
    Row *rowB = (Row *)b;
    
    // If number of soldiers is different, sort in ascending order
    if (rowA->numSoldiers != rowB->numSoldiers) {
        return rowA->numSoldiers - rowB->numSoldiers;
    }
    
    // If number of soldiers is the same, sort based on row index in ascending order
    return rowA->rowIndex - rowB->rowIndex;
}

int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize) {
    // Allocate memory for the result array
    int *result = malloc(k * sizeof(int));
    *returnSize = k;
    
    // Create an array of Rows to store the row index and number of soldiers
    Row *rows = malloc(matSize * sizeof(Row));
    
    // Iterate over each row and count the number of soldiers
    for (int i = 0; i < matSize; i++) {
        int count = 0;
        for (int j = 0; j < *matColSize; j++) {
            if (mat[i][j] == 1) {
                count++;
            } else {
                break;
            }
        }
        rows[i].rowIndex = i;
        rows[i].numSoldiers = count;
    }
    
    // Sort the rows array based on the number of soldiers and row index
    qsort(rows, matSize, sizeof(Row), compare);
    
    // Get the indices of the k weakest rows
    for (int i = 0; i < k; i++) {
        result[i] = rows[i].rowIndex;
    }
    
    // Free memory
    free(rows);
    
    return result;
}

int main() {
    int mat[4][5] = {{1, 1, 0, 0, 0},
                     {1, 1, 1, 1, 0},
                     {1, 0, 0, 0, 0},
                     {1, 1, 0, 0, 0}};
                     
    int k = 2;
    int matSize = 4;
    int matColSize = 5;
    int returnSize;
    
    // Convert the matrix to 2D array representation
    int **matPtr = malloc(matSize * sizeof(int *));
    for (int i = 0; i < matSize; i++) {
        matPtr[i] = mat[i];
    }
    
    int *result = kWeakestRows(matPtr, matSize, &matColSize, k, &returnSize);
    
    // Print the result
    printf("Indices of the k weakest rows: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    
    // Free memory
    free(matPtr);
    free(result);
    
    return 0;
}
