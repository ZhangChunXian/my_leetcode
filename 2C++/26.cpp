#include "cpp_header.h"
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();

        if (size == 0 || size == 1) return size;

        int k = 1;
        for (int i = 1; i < size; i++) {
            if (nums[i] != nums[i - 1]) {
                nums[k++] = nums[i];
            }
        }

        return k;
    }
};