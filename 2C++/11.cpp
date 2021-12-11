#include "cpp_header.h"

/**
 * @brief 双指针法 官方题解
 * 执行用时：72 ms, 在所有 C++ 提交中击败了70.79%的用户
 * 内存消耗：57.7 MB, 在所有 C++ 提交中击败了8.43%的用户
 */

class Solution {
public:
    int maxArea(vector<int>& height) {
      int res = 0;
      int left = 0, right = height.size() - 1;

      while(left < right) {
        res = max(min(height[left], height[right]) * (right - left), res);
        height[left] < height[right] ? left++ : right--;
      }

      return res;
    }
};