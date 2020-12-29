#include "cpp_header.h"

/**
 * @brief Solution 1 Use Hashmap
 * 执行用时：100 ms, 在所有 C++ 提交中击败了6.28%的用户
 * 内存消耗：20.6 MB, 在所有 C++ 提交中击败了5.00%的用户
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> HashTable;

        for (auto num : nums) {
            ++HashTable[num];
        }
        int res;
        for (const auto element : HashTable) {
            if(element.second == 1) {
                res = element.first;
            }
        }
        return res;
    }
};


class Solution {
    public:
        int singleNumber(vector<int>&nums){
            int res = 0;
            for (auto i: nums) {
                res ^= i;
            }

            return res;
        }
}