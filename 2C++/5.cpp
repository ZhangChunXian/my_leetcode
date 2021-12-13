# include "cpp_header.h"

/**
 * @brief 动态规划
 * 执行用时：756 ms, 在所有 C++ 提交中击败了6.05%的用户
 * 内存消耗：378 MB, 在所有 C++ 提交中击败了16.19%的用户
 */
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) {
            return s;
        }

        int maxLen = 1;
        int begin = 0;

        // dp[i][j] 表示 s[i...j] 是否是回文串
        vector<vector<int>> dp(n, vector<int>(n));

        // 初始化: 所有长度为1的子串都是回文串
        for(int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        // 递推开始, 先枚举子串长度
        for(int L = 2; L <= n; L++) {
            // 枚举左边界, 左边界的上限设置可以宽松一些
            for(int i = 0; i < n; i++) {
                // 由 L 和 i 可以确定右边界, 即 j - i + 1 = L, 得到
                int j = L + i - 1;
                // 如果右边界越界, 就可以退出当前循环
                if (j >= n) {
                    break;
                }

                if (s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    if (j - i < 3) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                // 只要dp[i][L] == true成立, 即表示s[i..L]是回文, 此时可以记录回文长度
                if(dp[i][j] && j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    begin = i;
                }
            }
        }

        return s.substr(begin, maxLen);
    }
};