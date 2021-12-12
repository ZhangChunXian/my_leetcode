#include "cpp_header.h"

/**
 * @brief 执行用时：24 ms, 在所有 C++ 提交中击败了82.90%的用户
 * 内存消耗：17 MB, 在所有 C++ 提交中击败了63.74%的用户
 * 
 */
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int numOfChildren = g.size(), numOfCookies = s.size();
        int count = 0;
        for (int i = 0, j = 0; i < numOfChildren && j < numOfCookies; i++, j++) {
            while (j < numOfCookies && g[i] > s[j]) {
                j++;
            }
            if (j < numOfCookies) {
                count++;
            }
        }
        return count;
    }
};