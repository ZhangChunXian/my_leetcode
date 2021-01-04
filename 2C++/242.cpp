#include "cpp_header.h"
/**
 * @brief 利用哈希表来解决, 2021年1月3日独立做出
 * 执行用时：20 ms, 在所有 C++ 提交中击败了49.22%的用户
 * 内存消耗：7.7 MB, 在所有 C++ 提交中击败了8.24%的用户
 */
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false; // 如果字符串长度不相等, 返回false

        unordered_map<char, int> HashmapFor_s, HashmapFor_t;

        for (auto character : s) {
            HashmapFor_s[character]++;
        }

        for (auto character : t) {
            HashmapFor_t[character]++;
        }

        return HashmapFor_s == HashmapFor_t;
    }
};