#include "cpp_header.h"
/**
 * @brief 哈希表方法
 * 执行用时：4 ms, 在所有 C++ 提交中击败了64.60%的用户
 * 内存消耗：6.5 MB, 在所有 C++ 提交中击败了53.34%的用户通过测试用例：95 / 95
 */
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> count;
        int ans = 0;
        for (char c : s) {
            ++count[c];
        }

        for(auto p : count) {
            int v = p.second;
            ans += v / 2 * 2;
            if (v % 2 == 1 && ans % 2 == 0)
                ++ans;
        }

        return ans;
    }
};