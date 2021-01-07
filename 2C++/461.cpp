#include "cpp_header.h"
/**
 * @brief 2021年1月7日 09:03:48 独立做出
 * 执行用时：4 ms, 在所有 C++ 提交中击败了31.17%的用户
 * 内存消耗：6.3 MB, 在所有 C++ 提交中击败了19.31%的用户
 */
class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;

        for (int i = 0; i < 32; i++) {
            int temp1 = x & 0x1;
            int temp2 = y & 0x1;

            res += !(temp1 == temp2);

            x = x / 2;
            y = y / 2;

            if (x == 0 && y == 0) return res;
        }

        return res;
    }
};