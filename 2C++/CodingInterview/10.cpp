# include "cpp_header.h"

/**
 * @brief 动态规划
 * 执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户内存消耗：5.9 MB, 在所有 C++ 提交中击败了50.55%的用户
 */

class Solution {
public:
    int fib(int n) {
        int Mod = 1000000007;
        if (n < 2) {
            return n;
        }

        int p = 0, q = 0, r = 1;
        for(int i = 2; i <= n; i++) {
            p = q;
            q = r;
            r = (p + q) % Mod;
        }
        return r;
    }
};