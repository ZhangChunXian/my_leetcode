#include "cpp_header.h"

/**
 * @brief 哈希表 + 贪心算法
 * 执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户内存消耗：6.1 MB, 在所有 C++ 提交中击败了37.34%的用户
 */
class Solution {
public:
    int balancedStringSplit(string s) {
        unordered_map<char, int> count;
        int res = 0;

        for(char c : s) {
            count[c]++;

            if (count['R'] == count['L']) {
                res++;
                count['R'] = 0;
                count['L'] = 0;
            }
        }

        return res;
    }
};