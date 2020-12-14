#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int main() {
    vector<int> myvector;
    myvector.push_back(1);
    myvector.push_back(2);
    myvector.push_back(3);
    myvector.push_back(4);
    myvector.push_back(5);
    myvector.push_back(6);
    myvector.push_back(7);
    myvector.push_back(8);

    auto res = myvector.front() > myvector.back() ? myvector.front() - myvector.back() : myvector.back() - myvector.front();

    cout << res;

    return 0;
}

