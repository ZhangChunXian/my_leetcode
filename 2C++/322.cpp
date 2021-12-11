#include "cpp_header.h"
/**
 * @brief 动态规划 官方题解
 * 执行用时：80 ms, 在所有 C++ 提交中击败了54.50%的用户
 * 内存消耗：14.1 MB, 在所有 C++ 提交中击败了51.91%的用户通过测试用例：188 / 188
 */
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
      int Max = amount + 1;
      vector<int> dp(amount + 1, Max);
      dp[0] = 0;
      for(int i = 1; i <= amount; i++) {
        for(int j = 0; j < (int)coins.size(); j++) {
          if (coins[j] <= i) {
            dp[i] = min(dp[i], dp[i - coins[j]] + 1);
          }
        }
      }
      return dp[amount] > amount ? -1 : dp[amount];
    }
};