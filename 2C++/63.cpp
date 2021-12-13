#include "cpp_header.h"

/**
 * @brief 动态规划解法
 * 执行用时：4 ms, 在所有 C++ 提交中击败了72.72%的用户
 * 内存消耗：7.6 MB, 在所有 C++ 提交中击败了41.92%的用户
 */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> path(m, vector<int>(n, 0));

        // 第一行边界
        for(int i = 0; i < n; i++) {
            obstacleGrid[0][i] == 1 ? path[0][i] = 0 : path[0][i] = 1;
            if (i > 0 && path[0][i- 1] == 0) {
                path[0][i] = 0;
            }
        }

        // 第一列边界
        for(int i = 0; i < m; i++) {
            obstacleGrid[i][0] == 1 ? path[i][0] = 0 : path[i][0] = 1;
            if (i > 0 && path[i - 1][0] == 0) {
                path[i][0] = 0;
            }
        }

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    path[i][j] = 0;
                } else {
                    path[i][j] = path[i - 1][j] + path[i][j - 1];
                }
            }
        }

        return path[m - 1][n - 1];
    }
};