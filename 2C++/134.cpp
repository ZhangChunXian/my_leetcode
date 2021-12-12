#include "cpp_header.h"

/**
 * @brief leetcode官方题解 贪心, 带数学证明
 * 执行用时：44 ms, 在所有 C++ 提交中击败了62.16%的用户
 * 内存消耗：48.6 MB, 在所有 C++ 提交中击败了30.12%的用户
 */
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int i = 0;
        while(i < n) {
            int sumOfGas = 0, sumOfCost = 0;
            int cnt = 0;
            while(cnt < n) {
                int j = (i  + cnt ) % n;
                sumOfGas += gas[j];
                sumOfCost += cost[j];
                if (sumOfGas < sumOfCost) {
                    break;
                }
                cnt++;
            }

            if (cnt == n) {
                return i;
            } else {
                i = i + cnt + 1;
            }
        }

        return -1;
    }
};