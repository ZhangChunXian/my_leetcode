#include "cpp_header.h"
/**
 * @brief 动态规划递归方法
 * 执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
 * 内存消耗：7.6 MB, 在所有 C++ 提交中击败了22.15%的用户
 * 采用滚动的形式可以优化空间复杂度
 */

class Solution {
public:
    int rob(vector<int>& nums) {
      if (nums.size() == 1) return nums[0];
      if (nums.size() == 2) return max(nums[0], nums[1]);

      vector<int> res(nums.size(), 0);    // res[i]代表从第0间房子到第二间房子能偷到的最大数量
      res[0] = nums[0];
      res[1] = max(nums[0], nums[1]);

      for(int i = 2; i < nums.size(); i++) {
        res[i] = max(res[i - 2] + nums[i], res[i - 1]);
      }

      return max(res[nums.size() - 1], res[nums.size() - 2]);
    }
};

// 优化空间复杂度
class Solution {
public:
    int rob(vector<int>& nums) {
      if (nums.size() == 1) return nums[0];
      if (nums.size() == 2) return max(nums[0], nums[1]);

      int first = nums[0];
      int second = max(nums[0], nums[1]);

      for(int i = 2; i < nums.size(); i++) {
        int temp = second;
        second = max(first + nums[i], temp);
        first = temp;
      }

      return max(first, second);
    }
};