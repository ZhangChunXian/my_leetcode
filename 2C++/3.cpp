#include "cpp_header.h"
/**
 * @brief 2021年1月11日 09:02:35 独立做出, 虽然这个解法不太好
 * 执行用时：1952 ms, 在所有 C++ 提交中击败了5.00%的用户
 * 内存消耗：234.4 MB, 在所有 C++ 提交中击败了5.01%的用户
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0 || s.size() == 1) return s.size();
        int MaxLength = 1;
        for (int i = 0; i < s.size() - 1; i++) {    // 从第一位开始遍历

            int temp = 1;
            unordered_map<char, int> HashMap;
            HashMap.insert({s[i], 1});
            for (int j = i + 1; j < s.size(); j++) {
                if (HashMap.find(s[j]) != HashMap.end()) {   // 元素在哈希表中存在
                    break;
                }

                HashMap.insert({s[j], 1});
                temp++;

                MaxLength = (temp > MaxLength ? temp: MaxLength);
                if (MaxLength > s.size() - 1 - i) return MaxLength;
            }
        }

        return MaxLength;
    }
};