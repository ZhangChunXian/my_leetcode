#include "cpp_header.h"

int main() {
    int sum = 0, value = 0;
    while (cin >> value) {
        sum += value;
    }
    std::cout << "Sum is: " << sum << std::endl;
    return 0;
}