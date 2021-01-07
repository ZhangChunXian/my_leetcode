#include "cpp_header.h"
/**
 * @brief 2021年1月7日 15:16:01 费了一些力气, 最后从题解中找到思路后做出
 * 执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
 * 内存消耗：6.8 MB, 在所有 C++ 提交中击败了26.65%的用户
 */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (numRows == 0) return res;
        res.push_back(vector<int>{1});
        if (numRows == 1) return res;

        for (int i = 1; i < numRows; i++) {             // i是行, j是列
            vector<int> temp;
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) temp.push_back(1);
                else {
                    temp.push_back(res[i - 1][j - 1] + res[i - 1][j]);
                }
            }
            res.push_back(temp);
        }

        return res;
    }
};

/**
 * @brief 递归方法
 * 执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
 * 内存消耗：7.7 MB, 在所有 C++ 提交中击败了5.07%的用户
 */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (numRows == 0) return res;
        /* 基础情况 */
        res.push_back(vector<int>(1, 1));
        if (numRows == 1) return res;

        res = generate(numRows - 1);

        vector<int> LastRow;

        for (int i = 0; i < numRows; i++) {
            if (i == 0 || i == numRows - 1) {
                LastRow.push_back(1);
            }else {
            LastRow.push_back(res[numRows - 2][i] + res[numRows - 2][i - 1]);
            }
        }

        res.push_back(LastRow);

        return res;
    }
};