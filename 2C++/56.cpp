#include "cpp_header.h"
/**
 * @brief 2021年1月11日 11:15:50 独立写出, 算法时间复杂度高, 最后超时了
 * 下面答案未通过
 * ! if the size of a container has changed, the behavior of the iterator
 * ! of it will be unpredictable.
 */
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() < 2 ) return intervals;
        auto temp = intervals.begin();
        VectorSort(intervals, 0, intervals.size());
        for (int i = 0; i < intervals.size() - 1;) {
            temp = intervals.begin() + i;
            if (intervals[i][1] >= intervals[i + 1][0]) {       // 合并
                vector<int> TempVector;
                TempVector.push_back(intervals[i][0]);
                TempVector.push_back(intervals[i + 1][1] > intervals[i][1] ? intervals[i + 1][1] : intervals[i][1]);
                intervals.insert(temp, TempVector);
                intervals.erase(intervals.begin() + i + 1);
                intervals.erase(intervals.begin() + i + 1);
            }else i++;
        }

        return intervals;
    }

    void VectorSort(vector<vector<int>>& intervals, int low, int high) {
        // int low = 0, high = intervals.size() - 1;
        if (low < high) {
            int pivotpos = Partition(intervals, low, high);

            VectorSort(intervals, low, pivotpos - 1);
            VectorSort(intervals, pivotpos + 1, high);
        }
    }

    int Partition(vector<vector<int>>& intervals, int low, int high) {
        vector<int> pivot = intervals[low];

        while (low < high) {
            while (low < high && intervals[high][0] > pivot[0]) --high;
            intervals[low] = intervals[high];

            while (low < high && intervals[low][0] <= pivot[0]) ++low;
            intervals[high] = intervals[low];
        }

        intervals[low] = pivot;

        return low;
    }
};

/**
 * @brief 2021年1月11日 14:00:00 从官方题解中获取思路
 * 不在原数组基础上改动, 重新分配一个空白数组
 * 执行用时：52 ms, 在所有 C++ 提交中击败了74.28%的用户
 * 内存消耗：14.4 MB, 在所有 C++ 提交中击败了46.55%的用户
 */
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0 || intervals.size() == 1)
            return intervals;

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> Merged;
        for (int i = 0; i < intervals.size(); i++) {
            if (i == 0) Merged.push_back(intervals[0]);
            else {
                if (intervals[i][0] <= Merged.back()[1]) {
                    Merged.back()[1] = (intervals[i][1] > Merged.back()[1] ? intervals[i][1] : Merged.back()[1]);
                }else Merged.push_back(intervals[i]);
            }
        }

        return Merged;
    }
};