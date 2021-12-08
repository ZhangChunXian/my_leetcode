#include "cpp_header.h"

/**
 * @brief 有规律啊，剩余左括号总数要小于等于右括号。 递归把所有符合要求的加上去就行了：
 * 执行用时：4 ms, 在所有 C++ 提交中击败了71.75%的用户
 * 内存消耗：13.6 MB, 在所有 C++ 提交中击败了33.18%的用户
 */
class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
      getParenthesis("", n, n);
      return res;
    }

    void getParenthesis(string str, int left, int right) {
      if (left == 0 && right == 0) {
        res.emplace_back(str);
        return;
      }
      if (left == right) {
        // 剩余左右括号数相等, 以一个只能用左括号
        getParenthesis(str+"(", left - 1, right);
      } else if (left < right) {
        // 剩余左括号大于右括号, 下一个可以用左括号也可以用右括号
        if(left > 0) {
          getParenthesis(str+"(", left - 1, right);
        }
        getParenthesis(str+")", left, right - 1);
      }
    }
};

/**
 * @brief 动态规划方法
 *!! 未通过
 */

class Solution {
public:
    vector<string> generateParenthesis(int n) {
      if(n == 0) {
        return vector<string>{""};
      }
      vector<vector<string>> total(n, vector<string>{});   // total[i]表示i对括号时的所有情况
      total[0].push_back("");
      total[1].push_back("()");
      for(int i = 2; i <= n; i++) {
        for(int j = 0; j <= i - 1; j++) {
          vector<string> now_list1 = total[j];
          vector<string> now_list2 = total[i - 1 - j];
          for(int k = 0; k < now_list1.size(); k++) {
            for(int l = 0; l < now_list2.size(); l++) {
              total[i].push_back("(" + now_list1[k] + ")" + now_list2[l]);
            }
          }
        }
      }
      return total[n];
    }
};