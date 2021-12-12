#include "cpp_header.h"

/**
 * @brief 自定义排序, 看别人的题解
 * 执行用时：8 ms, 在所有 C++ 提交中击败了66.58%的用户
 * 内存消耗：11.1 MB, 在所有 C++ 提交中击败了39.41%的用户
 */
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v;

        for(int t : nums) v.emplace_back(to_string(t));

        sort(v.begin(), v.end(), [](const string &a, const string &b) {
            return a + b > b + a;       // 字符串先后组合大小降序排列
        });

        if (v[0] == "0") return "0";
        string ans= "";
        for(string t : v) ans += t;
        return ans;
    }
};