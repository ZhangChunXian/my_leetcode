#include "cpp_header.h"
/**
 * @brief 动态规划
 * 执行用时：4 ms, 在所有 C++ 提交中击败了98.46%的用户
 * 内存消耗：9.9 MB, 在所有 C++ 提交中击败了11.81%的用户
 * 
 */
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
      int m = grid.size();
      int n = grid[0].size();
      vector<vector<int>> minPath(m, vector<int>(n, 0));

      minPath[0][0] = grid[0][0];
      // 边界情况
      for(int i = 1; i < m; i++) {
        minPath[i][0] = minPath[i - 1][0] + grid[i][0];
      }
      for(int i = 1; i < n; i++) {
        minPath[0][i] = minPath[0][i - 1] + grid[0][i];
      }

      for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
          minPath[i][j] = min(minPath[i - 1][j], minPath[i][j - 1]) + grid[i][j];
        }
      }

      return minPath[m - 1][n - 1];
    }
};