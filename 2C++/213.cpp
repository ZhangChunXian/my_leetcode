#include "cpp_header.h"

/**
 * @brief 动态规划迭代解法
 * 执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
 * 内存消耗：7.7 MB, 在所有 C++ 提交中击败了45.06%的用户
 */
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);


        return max(robber(nums, 0, nums.size() - 2), robber(nums, 1, nums.size() - 1));
    }

    int robber(vector<int>& nums, int start, int end) {
        int first = nums[start];
        int second = max(nums[start], nums[start + 1]);
        if(end - start == 1) return max(first, second);
        int temp = 0;

        for(int i = start + 2; i < end + 1; i++) {
            temp = max(first + nums[i], second);
            first = second;
            second = temp;
        }

        return temp;
    }
};