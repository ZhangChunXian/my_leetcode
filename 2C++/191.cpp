#include "cpp_header.h"
/**
 * @brief 2021年1月7日 08:54:16 独立做出
 * 执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
 * 内存消耗：6.1 MB, 在所有 C++ 提交中击败了66.56%的用户
 */
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;

        for (int i = 0; i < 32; i++) {
            res += n % 2;
            n = n / 2;

            if (n == 0) return res;
        }

        return res;
    }
};
