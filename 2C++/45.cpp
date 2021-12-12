#include "cpp_header.h"


/**
 * @brief 思路1, 动态规划(马上想到的思路)
 * 时间复杂度(O^2)
 * 执行用时：1196 ms, 在所有 C++ 提交中击败了5.02%的用户
 * 内存消耗：16.6 MB, 在所有 C++ 提交中击败了10.38%的用户
 */
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, INT_MAX);
        res[0] = 0;

        for(int i = 1; i < n; i++) {
            for(int j = i - 1; j >= 0; j--) {
                if(nums[j] >= i - j) {
                    res[i] = min(res[i], res[j] + 1);
                }
            }
        }

        return res[n - 1];
    }
};

/**
 * @brief 贪心算法(官方题解思路)
 * 执行用时：8 ms, 在所有 C++ 提交中击败了95.50%的用户
 * 内存消耗：16 MB, 在所有 C++ 提交中击败了50.19%的用户
 */
class Solution {
public:
    int jump(vector<int>& nums) {
        int maxPos = 0, n = nums.size(), end = 0, step = 0;
        for(int i = 0 ; i < n - 1; ++i) {
            if(maxPos >= i) {
                maxPos = max(maxPos, i + nums[i]);
                if (i == end) {
                    end = maxPos;
                    ++step;
                }
            }
        }
        return step;
    }
};
