#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> myvector;
    myvector.push_back(1);
    myvector.push_back(2);
    myvector.push_back(3);
    myvector.push_back(4);
    myvector.push_back(5);

    vector<int>::iterator it;

    it = myvector.begin();
    myvector.erase(it);

    for (auto it = myvector.begin(); it != myvector.end(); ++it) {
        cout << ' ' << *it;
    }

    return 0;
}