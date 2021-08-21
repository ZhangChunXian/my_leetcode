#include "cpp_header.h"

/**
 * @brief 解法一 暴力解法
 *  执行用时：28 ms, 在所有 C++ 提交中击败了50.96%的用户
    内存消耗：13.8 MB, 在所有 C++ 提交中击败了6.94%的用户
 */
class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        maxSize = size;
    }

    double next(int val) {
        sum = 0;
        count = 0;
        myQueue.push(val);
        myVector.push_back(val);
        if (myVector.size() <= maxSize) {
            for (auto i = myVector.end() - 1; i >= myVector.begin(); i--) {
                sum += *i;
                count++;
            }
        } else {
            for (auto i = myVector.end() - 1; count < maxSize; i--) {
                sum += *i;
                count++;
            }
        }
        return (double)sum / (double)count;
    }
private:
    queue<int> myQueue;
    int maxSize;
    vector<int> myVector;
    int sum;
    int count;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */