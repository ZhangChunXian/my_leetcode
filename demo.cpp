#include "cpp_header.h"
class Solution {
public:
    int reverse(int x) {
        if (x >= 0) {
        string str = to_string(x);
        ::reverse(str.begin(), str.end());

        stringstream StringToInt(str);
        int res = 0;
        StringToInt >> res;
        res = x;
        }

        return x;
    }
};