#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 typedef struct {
     int index;
     int count;
 } Row;

int compare(const void *a, const void *b)
{
    Row *rowA = (Row *)a;
    Row *rowB = (Row *)b;

    if (rowA->count == rowB->count) {
	return rowA->index - rowB->index;
    } else {
	return rowA->count - rowB->count;
    }
}


int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize)
{
	Row *rows = NULL;
    	int *answer = NULL;

    	rows = (Row *)malloc(matSize * sizeof(Row));
    	answer = (int *)malloc(k * sizeof(int));
    	*returnSize = k;

    	if (rows == NULL || answer == NULL) 
	{
		printf("Error: malloc failed\n");
		exit(1);
    	}

    	for (int i = 0; i < matSize; i++)
    	{
		rows[i].index = i;
		rows[i].count = 0;
		for (int j = 0; j < *matColSize; j++) {
		    if (mat[i][j] == 1) {
			rows[i].count++;
		    } else {
			break;
		    }
		}
    	}

    	qsort(rows, matSize, sizeof(Row), compare);
	
    	for (int i = 0; i < k; i++) {
		answer[i] = rows[i].index;
    	}
	
    	free(rows);
	
    	return answer;


}

