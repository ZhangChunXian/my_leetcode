/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i = 0, j = 0, sum = 0;

    for(i = 0; i < numsSize; i++)
    {
        for (j = i + 1; j < numsSize; j++)
        {
            if(nums[i] + nums[j] == target)
            {
                returnSize = (int *)malloc(sizeof(int) * 2);
                returnSize[0] = i;
                returnSize[1] = j;
                printf("%d %d", i, j);
                return returnSize;
            }
        }
    }

    return returnSize;
}