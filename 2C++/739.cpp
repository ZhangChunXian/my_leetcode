#include "cpp_header.h"

/* 1. 该解法时间复杂度过高, 无法AC */
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> res(T.size(), 0);

        for (int i = 0; i < T.size() - 1; i++) {
            for (int j = i + 1; j < T.size(); j++) {
                if (T[j] > T[i]) {
                    res[i] = j - i;
                    break;
                }
            }
        }
        return res;
    }
};