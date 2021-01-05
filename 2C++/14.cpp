#include "cpp_header.h"

/**
* 对每个数组的同一位置进行扫描, 如果扫描结果都相同, 那么就加入到结果数列中
* 2021年1月5日 15:31:43 独立做出
* 执行用时：4 ms, 在所有 C++ 提交中击败了92.75%的用户
* 内存消耗：9.4 MB, 在所有 C++ 提交中击败了55.52%的用户
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0 ) return "";

        string res;

        int i = 0, j = 0;       // i为扫描到的每个数列的位数

        /*
        求字符串数组中字符串的字符最小个数
        */
        int MinCharNum = strs[0].size();
        for (i = 1; i < strs.size(); i++) {
            if (MinCharNum > strs[i].size()) {
                MinCharNum = strs[i].size();
            }
            if (MinCharNum == 0) return "";
        }

        // 对每个字符串从前到后进行字符串的扫描
        for (i = 0; i < MinCharNum; i++) {
            char CurrentChar = strs[0][i];

            for (j = 1; j < strs.size(); j++) {
                if (strs[j][i] != CurrentChar) {
                    return res;
                }
            }
            res += CurrentChar;
        }

        return res;
    }
};

/**
 * @brief 高赞题解, 比我自己写的代码量要小很多
 * 
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";

        if (strs.size() == 0) return prefix;

        /** check char by char, for each char, check all the string word */
        for (int k = 0; k < strs[0].size(); k++) {       //? 这两句相对于我的代码做了优化, 省去了求字符串数组中字符串的字符最小个数的步骤
            int i = 1;
            for (; i < strs.size() && strs[i].size() > k; i++) {            //? 这是第二句话
                if (strs[i][k] != strs[0][k])
                    return prefix;
            }

            if (i == strs.size()) prefix += strs[0][k];
        }
        return prefix;
    }
};