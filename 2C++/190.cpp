#include "cpp_header.h"
/**
 * @brief 2021年1月7日 10:44:34 独立做出
 * 执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
 * 内存消耗：6.4 MB, 在所有 C++ 提交中击败了6.02%的用户
 */
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;

        for (int i = 0; i < 32; i++) {
            int temp = n % 2;
            n = n / 2;

            res += (temp == 0) ? 0 : pow(2, 31 - i);

            if (n == 0) return res;
        }
        return res;
    }
};
