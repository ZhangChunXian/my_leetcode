#include "cpp_header.h"
/**
 * @file 88.cpp
 * @brief 简单题, 一次写出
 * 执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
 * 内存消耗：9.3 MB, 在所有 C++ 提交中击败了31.73%的用户
 * @version 0.1
 * @date 2021-01-04
 * @copyright Copyright (c) 2021
 */

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = m; i < m + n; i++) {
            nums1[i] = nums2[i - m];
        }

        sort(nums1.begin(), nums1.begin() + m + n);
    }
};

/**
 * @brief 运用双指针的方法 思路来自官方题解
 * 
 */
class Solution {
public:
    void merge(vector<int>&nums1, int m, vector<int>& nums2, int n) {
        vector<int> TempNums = nums1;
        int Num1Pointer = 0, Num2Pointer = 0;
    }
};