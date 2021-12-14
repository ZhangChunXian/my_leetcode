#include "cpp_header.h"

/**
 * @brief leetcode官方题解
 * 执行用时：4 ms, 在所有 C++ 提交中击败了79.14%的用户
 * 内存消耗：13.9 MB, 在所有 C++ 提交中击败了5.00%的用户
 */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> maxF(nums), minF(nums);
        for(int i = 1; i < nums.size(); i++) {
            maxF[i] = max(maxF[i - 1] * nums[i], max(nums[i], minF[i - 1] * nums[i]));
            minF[i] = min(minF[i - 1] * nums[i], min(nums[i], maxF[i - 1] * nums[i]));
        }

        return *max_element(maxF.begin(), maxF.end());
    }
};