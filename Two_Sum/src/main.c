#include <stdio.h>
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){

    int *answer = 0;

    answer = (int *)malloc(2 * sizeof(int));
    *returnSize = 2;

	if (answer == NULL) {
		printf("Error: malloc failed\n");
		exit(1);
	}
	if (nums == NULL || numsSize < 2 || target < 0 || returnSize == NULL) {
		printf("Error: invalid input\n");
		exit(1);
	}

    for (int i = 0; i < numsSize; i++) {
	for (int j = i+1; j < numsSize; j++) {
	    if (nums[i] + nums[j] == target) {
		answer[0] = i;
		answer[1] = j;

		return answer;
	    }
	}
    }

    return answer;

}