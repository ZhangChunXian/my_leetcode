#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;

    // Inserting elements in vector
    for (int i = 0; i < 8; i++) {
        v.push_back(i + 10);
    }

    reverse(v.begin() + 5, v. begin() + 8);

    vector<int>::iterator it;

    for (it = v.begin(); it != v.end(); it++)
        cout << (*it) << " ";
}