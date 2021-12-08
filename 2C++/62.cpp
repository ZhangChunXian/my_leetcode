#include "cpp_header.h"

/**
 * @brief 动态规划
 * 执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
 * 内存消耗：6.4 MB, 在所有 C++ 提交中击败了33.97%的用户
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
      if(m == 1 && n == 1) return 1;
      vector<vector<int>> paths(m, vector<int>(n, 0));

      // 边界
      for(int i = 0; i < m; i++) {
        paths[i][0] = 1;
      }

      for(int i = 1; i < n; i++) {
        paths[0][i] = 1;
      }

      if(m == 1 || n == 1) return paths[m - 1][n - 1];

      // 非边界
      for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
          paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
        }
      }

      return paths[m - 1][n - 1];
    }
};