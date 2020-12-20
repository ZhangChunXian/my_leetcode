#include "cpp_header.h"
class Solution {
public:
    /**
     * @brief 方法一
     * 执行用时：12 ms, 在所有 C++ 提交中击败了50.89%的用户
     * 内存消耗：10.1 MB, 在所有 C++ 提交中击败了9.30%的用户
     */
    void rotate(vector<int>& nums, int k) {
        int offset = k % nums.size(); // offset为数组实际偏移量
        vector<int> temp(offset, 0);  // 临时数组, 存放在移动的过程中被覆盖的元素

        for (int i = 0; i < offset; i++)  {// 临时数组存储数组的offset个值
            temp[i] = nums[nums.size() - 1 - i];
        }

        for (int i = nums.size() - offset - 1; i >= 0; i--) {   // 为开头元素赋值
            nums[i + offset] = nums[i];
        }

        for (int i = 0; i < offset; i++) {
            nums[i] = temp[offset - i - 1];
        }

    }// rotate


    void rotate(vector<int>& nums, int k) {
        // 三次翻转搞定
        k = k % nums.size();
        reverse(nums.begin(), nums.begin() + nums.size() - k);
        reverse(nums.begin() + nums.size() - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
}; // class Solution

