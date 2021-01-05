#include "cpp_header.h"
/**
 * @brief 看别人的回答
 */
class Solution {
public:
    int myAtoi(string str) {
        long result = 0;
        int indicator = 1;

        auto i = str.find_first_not_of(' ');

        if (i == - 1) return 0;
        if (str[i] == '-' || str[i] == '+')
            indicator = (str[i++] == '-') ? -1 : 1;

        while (isdigit(str[i])) {
            result = result * 10 + (str[i++] - '0');
            if (result * indicator >= INT_MAX) return INT_MAX;
            if (result * indicator <= INT_MIN) return INT_MIN;
        }
        return result * indicator;
    }
};

