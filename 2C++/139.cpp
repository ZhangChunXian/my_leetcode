#include "cpp_header.h"

/**
 * @brief leetcode官方题解
 * 执行用时：20 ms, 在所有 C++ 提交中击败了30.09%的用户
 * 内存消耗：12.7 MB, 在所有 C++ 提交中击败了64.45%的用户
 */
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        auto wordDictSet = unordered_set<string> ();
        for(auto word: wordDict) {
            wordDictSet.insert(word);
        }

        auto dp = vector<bool>(s.size() + 1);
        dp[0] = true;

        for(int i = 1; i <= s.size(); i++) {
            for(int j = 0; j < i; j++) {
                if (dp[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};