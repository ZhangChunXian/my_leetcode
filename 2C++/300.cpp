#include "cpp_header.h"

/**
 * @brief 动态规划
 * 时间复杂度O(n^2)
 * 执行用时：264 ms, 在所有 C++ 提交中击败了53.96%的用户
 * 内存消耗：10.2 MB, 在所有 C++ 提交中击败了70.78%的用户
 * 
 */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      int n = nums.size();
      vector<int> res(n, 1);      // res[i]代表以nums[i]结尾的最长递增子序列长度

      for(int i = 1; i < n; i++) {
        for(int j = 0; j < i - 1; j++) {
          if(nums[j] < nums[i]) {
            res[i] = max(res[i], res[j] + 1);
          }
        }
      }

      return *max_element(res.begin(), res.end());
    }
};

/**
 * @brief 动态规划
 * 时间
 */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      int n = nums.size();
      vector<int> res(n, 1);      // res[i]


    }
};