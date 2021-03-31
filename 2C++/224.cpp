/** 1. 思路
 * 先前缀表达式转后缀表达式
 * 再后缀表达式求值
 */
#include <string>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    int calculate(string s) {
        stack<string> tempStack;
        vector<string> postFix;                                 // 后缀表达式string容器
        for (int i = 0; i < s.length();) {
            if (s[i] >= '0' && s[i] <= '9') {                   // s[i]为操作数
                string num;
                for(; s[i] >= '0' && s[i] <= '9' && i < s.length(); i++) {
                    num += s[i];
                }
                postFix.push_back(num);
            } else if (s[i] == '(') {                           // 即s[i]为左括号 (
                string leftBracket;
                leftBracket += s[i];
                tempStack.push(leftBracket);
                i++;
            } else if (s[i] == ')') {
                if (tempStack.top() == "+" ||
                    tempStack.top() == "-" ||
                    tempStack.top() == "*" ||
                    tempStack.top() == "/") {
                        postFix.push_back(tempStack.top());
                        tempStack.pop();
                    }else if (tempStack.top() == "(") {
                        tempStack.pop();
                        i++;
                        continue;
                    }
            } else if (s[i] == '+' || s[i] == '-') {
                if (!tempStack.empty() && (tempStack.top() == "+" || tempStack.top() == "-")) {
                    postFix.push_back(tempStack.top());
                    tempStack.pop();
                }else if (tempStack.empty()) {
                    i++;
                }else if (tempStack.top() == "(") {
                    
                }
            }
        }
    }
};