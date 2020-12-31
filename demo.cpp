#include "cpp_header.h"

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

size_t hasher(const Sales_data &sd) {
    return hash<string>()(sd.isbn());
}

bool eqOp(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.isbn() == rhs.isbn();
}

int main() {
    using SD_multiset = unordered_multiset<Sales_data,
                        decltype(hasher)*, decltype(eqOp)*>;

    // arguments are the bucket size and pointers to the hash function and equality operator
    SD_multiset bookstore(42, hasher, eqOp);
}