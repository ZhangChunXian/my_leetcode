#include "cpp_header.h"
/**
 * @brief 2021年1月7日 16:29:01 独立做出
 * 执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
 * 内存消耗：6.6 MB, 在所有 C++ 提交中击败了56.36%的用户
 */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        res.push_back(1);                           // 第零行
        if (rowIndex == 0) return res;

        for (int i = 1; i <= rowIndex; i++) {       // 行
            vector<int> temp = res;
            res.clear();
            for (int j = 0; j <= i; j++) {    // 列
                if (j == 0 || j == i) res.push_back(1);
                else {
                    res.push_back(temp[j] + temp[j - 1]);
                }
            }
        }

        return res;
    }
};