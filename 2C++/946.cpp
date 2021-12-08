#include "cpp_header.h"

/**
 * @brief 模拟栈操作方法
 * 执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
 * 内存消耗：14.8 MB, 在所有 C++ 提交中击败了88.63%的用户
 */
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> simulator;
        int index = 0;

        for(int i = 0; i < pushed.size(); ++i)
        {
            simulator.push(pushed[i]);
            while(simulator.size() && simulator.top() == popped[index])
            {
                simulator.pop();
                index++;
            }
        }
        return index == popped.size();
    }
};