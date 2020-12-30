#include "cpp_header.h"

/**
 * @brief 基本思路:
 * 先对个位数进行分析, 分三种情况
 * 再对其他位数进行分析(如果有的话), 也是分三种情况, 成功解开
 * 算法性能: 执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
 * 内存消耗：9 MB, 在所有 C++ 提交中击败了20.13%的用户
 */
class Solution {
public:
    vector<int> plusOne(vector<int> digits) {
        int size = digits.size();

        // 对各位做特殊处理
        if(digits[size - 1] == 9 && size > 1) {
            digits[size - 1] = 0;
            digits[size - 2]++;
        }else if (digits[size - 1] == 9 && size == 1) {
            digits[size - 1] = 0;
            digits.insert(digits.begin(), 1);
        }else if (digits[size - 1] < 9) {
            digits[size - 1]++;
        }

        for(int i = size - 2; i >= 0; i--) {
            if (digits[i] == 10 && i > 0) {
                digits[i] = 0;
                digits[i - 1]++;
            }else if (digits[i] == 10 && i == 0) {
                digits[i] = 0;
                digits.insert(digits.begin(), 1);
            }else if (digits[i] < 10) {
                break;
            }
        }

        return digits;

    }
};

/**
 * @brief C++高赞solution
 * 执行用时：4 ms, 在所有 C++ 提交中击败了64.52%的用户
 * 内存消耗：9 MB, 在所有 C++ 提交中击败了25.52%的用户
 */

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        for (int i = digits.size() - 1; i >= 0; i--) {
            ++digits[i];

            if (digits[i] != 10) {      // 该位没有产生进位
                return digits;
            }else {
                digits[i] = 0;          // 产生进位
            }
        }

        digits.insert(digits.begin(), 1);    // 如果首位也产生进位, 才会执行到这条语句, 否则循环中已经return
        return digits;
    }
};
