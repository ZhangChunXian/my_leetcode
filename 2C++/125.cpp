#include "cpp_header.h"
/**
 * @brief 2021年1月4日 20:06:46 利用双指针独立做出
 * 执行用时：12 ms, 在所有 C++ 提交中击败了38.88%的用户
 * 内存消耗：7.5 MB, 在所有 C++ 提交中击败了70.97%的用户
 */

class Solution {
public:
    bool isPalindrome(string s) {
        for (auto character : s) {
            character = ::toupper(character);
        }

        int begin = 0, end = s.size() - 1;

        while(begin < end) {
            while (!((s[begin] >= '0' && s[begin] <= '9') ||
                     (s[begin] >= 'A' && s[begin] <= 'Z'))) begin++;
            while (!((s[end] >= '0' && s[end] <= '9') ||
                     (s[end] >= 'A' && s[end] <= 'Z'))) end--;

            if (s[begin] != s[end]) return false;
            else {
                begin++;
                end--;
            }
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