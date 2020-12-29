#include "CHeader.h"

// Means 1: Sorting
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int *)b);
}

bool containsDuplicate(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);

    for(int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            return true;
        }
    }

    return false;
}

// Means 2: Hash Table
struct hashTable {
    int key;
    UT_hash_handle hh;
}