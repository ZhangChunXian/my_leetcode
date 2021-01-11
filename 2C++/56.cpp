#include "cpp_header.h"
/**
 * @brief 2021年1月11日 11:15:50 独立写出, 算法时间复杂度高, 最后超时了
 * 下面答案未通过
 */
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() < 2 ) return intervals;
        auto temp = intervals.begin();
        VectorSort(intervals);
        for (int i = 0; i < intervals.size() - 1;) {
            temp = intervals.begin() + i;
            if (intervals[i][1] >= intervals[i + 1][0]) {       // 合并
                vector<int> TempVector;
                TempVector.push_back(intervals[i][0]);
                TempVector.push_back(intervals[i + 1][1] > intervals[i][1] ? intervals[i + 1][1] : intervals[i][0]);
                intervals.insert(temp, TempVector);
                intervals.erase(intervals.begin() + i + 1);
                intervals.erase(intervals.begin() + i + 1);
            }else i++;

            return intervals;
        }
    }

    void VectorSort(vector<vector<int>>& intervals) {
        for (int i = 0; i < intervals.size() - 1; i++) {
            int MinIndex = i;

            for (int j = i + 1; j < intervals.size(); j++) {
                if (intervals[j][0] < intervals[MinIndex][0]) {
                    MinIndex = j;
                }
            }

            auto temp = intervals[i];
            intervals[i] = intervals[MinIndex];
            intervals[MinIndex] = temp;
        }
    }
};