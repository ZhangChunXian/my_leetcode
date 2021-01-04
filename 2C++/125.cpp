#include "cpp_header.h"
/**
 * @brief 2021年1月4日 20:06:46 利用双指针独立做出
 * 执行用时：12 ms, 在所有 C++ 提交中击败了38.88%的用户
 * 内存消耗：7.5 MB, 在所有 C++ 提交中击败了70.97%的用户
 */

class Solution {
public:
    bool isPalindrome(string s) {
        string sgood;
        for (char ch : s) {
            if (isalnum(ch)) {
                sgood += tolower(ch);
            }
        }

        int n = sgood.size();
        int left = 0, right = n - 1;

        while (left < right) {
            if (sgood[left] != sgood[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};


/**
 * @brief 官方题解
 * 
 */
class Solution {
public:
    bool isPalindrome(string s) {
        string sgood;

        for (char ch : s) {
            if (isalnum(ch)) {
                sgood += tolower(ch);
            }

        }
        string sgood_rev(sgood.rbegin(), sgood.rend());
        return sgood == sgood_rev;
    }
};