#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numbers;

        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i].length() > 1 || isdigit(tokens[i][0])) {
                numbers.push(stoi(tokens[i]));
            }else {
                int rNumber = numbers.top();
                numbers.pop();
                int lNumber = numbers.top();
                numbers.pop();
                if (tokens[i] == "+") {
                    numbers.push(lNumber + rNumber);
                } else if (tokens[i] == "-") {
                    numbers.push(lNumber - rNumber);
                } else if (tokens[i] == "*") {
                    numbers.push(lNumber * rNumber);
                } else if (tokens[i] == "/") {
                    numbers.push(lNumber / rNumber);
                }
            }
        }

        return numbers.top();
    }
};


int main() {
    Solution solution;
    vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    int res = solution.evalRPN(tokens);
    cout << res << endl;
    return 0;
}


/**
 * @brief 直接写的, 虽然复杂度不够好
 * 执行用时：16 ms, 在所有 C++ 提交中击败了11.67%的用户
 * 内存消耗：12.5 MB, 在所有 C++ 提交中击败了5.11%的用户
 */
class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
        if (tokens.size() == 1) return stoi(tokens[0]);
        stack<string> numbers;
        numbers.push(tokens[0]);

        int index = 1;
        while(index < tokens.size())
        {
            if(tokens[index] == "-") {
                int rightSide = stoi(numbers.top());
                numbers.pop();
                int leftSide = stoi(numbers.top());
                numbers.pop();
                numbers.push(to_string(leftSide - rightSide));
            } else if(tokens[index] == "+") {
                int rightSide = stoi(numbers.top());
                numbers.pop();
                int leftSide = stoi(numbers.top());
                numbers.pop();
                numbers.push(to_string(leftSide + rightSide));
            } else if(tokens[index] == "/") {
                int rightSide = stoi(numbers.top());
                numbers.pop();
                int leftSide = stoi(numbers.top());
                numbers.pop();
                numbers.push(to_string(leftSide / rightSide));
            } else if(tokens[index] == "*") {
                int rightSide = stoi(numbers.top());
                numbers.pop();
                int leftSide = stoi(numbers.top());
                numbers.pop();
                numbers.push(to_string(leftSide * rightSide));
            } else {
                numbers.push(tokens[index]);
            }
            index++;
        }

        return stoi(numbers.top());
    }
};