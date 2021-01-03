#include "cpp_header.h"

/**
 * @brief 2021年1/3 独立做出, 利用哈希表
 * 执行用时：204 ms, 在所有 C++ 提交中击败了9.09%的用户
 * 内存消耗：10.9 MB, 在所有 C++ 提交中击败了34.70%的用户
 */
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> HashMap;

        for (char character : s)
            HashMap[character]++;

        for (int i = 0; i < s.size(); ++i) {
            if (HashMap[s[i]] == 1) {
                return i;
            }
        }

        return -1;
    }
};