#include <stdio.h>

int removeDuplicates(int *nums, int numsSize);


int main() {
    int nums[] = {0,0,1,1,1,2,2,3,3,4};
    int numsSize = 10;

    numsSize = removeDuplicates(nums, numsSize);

    for(int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}

int removeDuplicates(int *nums, int numsSize) {
    if (numsSize == 0 || numsSize == 1) return numsSize;

    // k为计数器, 计算新表中不相同元素的个数
    int k = 1;

    for(int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[i - 1]) {
            nums[k++] = nums[i];
        }
    }

    return k;
}