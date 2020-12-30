#include "cpp_header.h"
/**
 * 本人第一次解放
 * 执行用时：12 ms, 在所有 C++ 提交中击败了46.59%的用户
 * 内存消耗：9.2 MB, 在所有 C++ 提交中击败了52.21%的用户
 */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int NonZeroCount = 0;           // 存储数组中非零值的数量
        for (auto i = nums.begin(); i != nums.end(); i++) {   // for循环整个数组, 如果是非零值, 则赋值到前面
            if (*i != 0) {
                nums[NonZeroCount] = *i;
                NonZeroCount++;
            }
        }

        for (int j = NonZeroCount; j < nums.size(); j++) {     // 将数组剩余部分填上零
            nums[j] = 0;
        }
    }
};