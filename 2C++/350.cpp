#include "cpp_header.h"


/**
 * @brief Using C++ STL function set_intersection
 * 执行用时：4 ms, 在所有 C++ 提交中击败了99.71%的用户
 * 内存消耗：10.3 MB, 在所有 C++ 提交中击败了77.29%的用户
 */
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums(nums1.size() + nums2.size());
        vector<int>::iterator it, sd;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        it = set_intersection(nums1.begin(),
                              nums1.end(),
                              nums2.begin(),
                              nums.end(),
                              nums.begin());

        vector<int> res;

        for (sd = nums.begin(); sd != it; sd++) {
            res.push_back(*sd);
        }

        return res;
    }
};
