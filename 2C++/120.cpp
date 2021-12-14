#include "cpp_header.h"

/**
 * 看官方题解的动态规划解法
 * 执行用时：8 ms, 在所有 C++ 提交中击败了44.76%的用户
 * 内存消耗：8.9 MB, 在所有 C++ 提交中击败了9.81%的用户
 */
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> minPath(n, vector<int>(n));
        minPath[0][0] = triangle[0][0];

        for(int i = 1; i < n; i++) {
            // 左边界
            minPath[i][0] = minPath[i - 1][0] + triangle[i][0];
            for(int j = 1; j < i; j++) {
                minPath[i][j] = min(minPath[i - 1][j - 1], minPath[i - 1][j]) + triangle[i][j];
            }
            minPath[i][i] = minPath[i - 1][i - 1] + triangle[i][i];
        }

        return *min_element(minPath[n - 1].begin(), minPath[n - 1].end());
    }
};