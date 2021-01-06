#include "cpp_header.h"
/**
 * @brief 2021年1月6日 21:04:53 独立做出
 * 执行用时：8 ms, 在所有 C++ 提交中击败了48.04%的用户
 * 内存消耗：8.1 MB, 在所有 C++ 提交中击败了39.23%的用户
*/
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;

        for (int i = 1; i <= n; i++) {
            if (i % 15 == 0) {
                res.push_back("FizzBuzz");
            }else if (i % 5 == 0) {
                res.push_back("Buzz");
            }else if (i % 3 == 0) {
                res.push_back("Fizz");
            }else res.push_back(to_string(i));
        }

        return res;
    }
};