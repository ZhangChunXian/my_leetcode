#include "cpp_header.h"


class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    int size = nums.size();

    vector<int> res(size, 0);
    res[0] = nums[0];
    for(int i = 1; i < size; i++)
    {
      res[i] = max(res[i - 1] + nums[i], nums[i]);
    }

    return *max_element(res.begin(), res.end());
  }
};