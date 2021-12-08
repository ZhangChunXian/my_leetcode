#include "cpp_header.h"

/**
 * @brief 迭代动态规划
 * 执行用时：56 ms, 在所有 C++ 提交中击败了47.14%的用户
 * 内存消耗：47.4 MB, 在所有 C++ 提交中击败了13.31%的用户
 */
class Solution {
public:
    bool canJump(vector<int>& nums) {
      if (nums.size() == 1) return true;
      vector<bool> reachable(nums.size(), false);
      reachable[0] = true;

      for(int i = 1; i < nums.size(); i++) {    // 检查每个点是否能到达
        for(int j = i - 1; j >= 0 && reachable[j] == true; j--) {
          if (nums[j] >= (i - j)) {
            reachable[i] = true;
            break;
          }
        }
      }

      return reachable[nums.size() - 1];
    }
};

/**
 * @brief 动态规划解法, 复杂度更好
 * 执行用时：44 ms, 在所有 C++ 提交中击败了90.59%的用户
 * 内存消耗：47.1 MB, 在所有 C++ 提交中击败了64.48%的用户
 */

class Solution {
public:
    bool canJump(vector<int>& nums) {
      int n = nums.size();
      int a = nums[0];
      for(int i = 1; i < n; i++) {
        if (a == 0) return false;
        a = max(a - 1, nums[i]);
      }
      return true;
    }
};