#include "cpp_header.h"
/**
 * @brief 2021年1月10日 20:13:42 独立做出, 采用多个if else 代码不够美观, 没有用栈这种数据结构
 * 执行用时：4 ms, 在所有 C++ 提交中击败了42.27%的用户
 * 内存消耗：6.6 MB, 在所有 C++ 提交中击败了32.56%的用户
 */
class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0) return false;    // 字符串元素个数为偶数是true的必要条件

        string::iterator it = s.begin();

        while (s.size() > 0) {
            if (*it == '(' || *it == '[' || *it == '{') {
                it++;
                continue;
            }else if (*it == ')') {
                if (it == s.begin()) return false;
                else if (*(it - 1) == '(') {
                    s.erase(it - 1, it + 1);
                    it--;
                }else return false;
            }else if (*it == ']') {
                if (it == s.begin()) return false;
                else if (*(it - 1) == '[') {
                    s.erase(it - 1, it + 1);
                    it--;
                }else return false;
            }else if (*it == '}') {
                if (it == s.begin()) return false;
                else if (*(it - 1) == '{') {
                    s.erase(it - 1, it + 1);
                    it--;
                }else return false;
            }

            if (it == s.end() && s.size() != 0) return false;
        }
        return true;
    }
};

/**
 * 高赞题解, 利用C++ STL中的stack数据结构(现有的轮子)做的
 * 执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
 * 内存消耗：6.5 MB, 在所有 C++ 提交中击败了53.25%的用户
 */
class Solution {
public:
    bool isValid(string s) {
        stack<char> temp;

        for (char c : s) {
            if (c == '[') temp.push(']');
            else if (c == '(') temp.push(')');
            else if (c == '{') temp.push('{');
            else if (temp.empty() || c != temp.top()) {
                return false;
            }else if (c == temp.top()) temp.pop();
        }
        return temp.empty();
    }
};