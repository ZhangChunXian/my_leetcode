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
