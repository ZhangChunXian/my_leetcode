#include "cpp_header.h"
/**
 * @brief 2021年1月9日 10:35:47 独立做出, 利用哈希表
 * 执行用时：36 ms, 在所有 C++ 提交中击败了35.07%的用户
 * 内存消耗：8.5 MB, 在所有 C++ 提交中击败了30.75%的用户
 */
class Solution {
public:
    int romanToInt(string s) {
        map<char, int> HashMap;

        HashMap.insert(pair<char, int>('I', 1));
        HashMap.insert(pair<char, int>('V', 5));
        HashMap.insert(pair<char, int>('X', 10));
        HashMap.insert(pair<char, int>('L', 50));
        HashMap.insert(pair<char, int>('C', 100));
        HashMap.insert(pair<char, int>('D', 500));
        HashMap.insert(pair<char, int>('M', 1000));

        int res = 0;
        for (auto it = s.begin(); it != s.end(); it++) {
            if ((it + 1) != s.end()  && (HashMap[*it] < HashMap[*(it + 1)])) {
                res -= HashMap[*it];
            }else {
                res += HashMap[*it];
            }
        }

        return res;
    }
};
