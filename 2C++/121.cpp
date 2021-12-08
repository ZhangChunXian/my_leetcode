#include "cpp_header.h"

/**
 * @brief 单调栈方法
 * 
 */

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int ans = 0;
    vector<int> St;
    prices.emplace_back(INT_MIN); // 哨兵
    for(int i = 0; i < prices.size(); i++) {
      while(!St.empty() && St.back() >  prices[i]) {    // 栈非空, 且入栈元素小于栈底元素
        ans = std::max(ans, St.back() - St.front());    // 维护一个最大值
        St.pop_back();
      }
      St.emplace_back(prices[i]);
    }

    return ans;
  }
};