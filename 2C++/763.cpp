#include "cpp_header.h"


/**
 * @brief 贪心算法, 第一次就写出来了
 * 执行用时：4 ms, 在所有 C++ 提交中击败了70.19%的用户
 * 内存消耗：6.6 MB, 在所有 C++ 提交中击败了24.24%的用户
 */
class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lastIndex;
        int latestIndex = 0;
        int temp = 0;
        vector<int> res;

        for(int i = 0; i < s.length(); i++) {
            lastIndex[s[i]] = i;
        }

        for(int i = 0; i < s.length(); i++) {
            latestIndex = max(latestIndex, lastIndex[s[i]]);
            temp++;

            if (i == latestIndex) {
                res.push_back(temp);
                temp = 0;
            }
        }

        return res;
    }
};