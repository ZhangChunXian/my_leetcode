#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2)
        {
            return s;
        }

        int maxLen = 1;
        int begin = 0;
        // dp[i][j] 表示s[i..j]是否是回文串
        vector<vector<int>> dp(n, vector<int>(n));
        // 初始化: 所有长度为1的之串都是回文串
        for(int i = 0; i < n; i++)
        {
            dp[i][i] = 1;
        }

        // 递推开始
        // 先枚举子串长度
        for(int L = 2; L <= n; L++) {
            // 枚举左边界, 左边界的上限设置的可以宽松一些
            for(int i = 0; i < n; i++) {
                // 由L和i可以确定右边界, 即 j - i + 1 = L 得
                int j = L + i - 1;
                // 如果右边界出界, 就可以退出当前循环
                if (j >= n) {
                    break;
                }
            }
        }
    }
};