#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    vector<int> vector1 = {4, 9, 5};
    vector<int> vector2 = {9, 4 , 9, 8, 4};

 

    // Initialize a vector to shore the common values
    // and an iterator to traverse this vector
    vector<int> v(vector1.size() + vector2.size());
    vector<int>::iterator it, st;

    it = set_intersection(vector1.begin(),
                          vector1.end(),
                          vector2.begin(),
                          vector2.end(),
                          v.begin());

    cout << "\nCommon elements:\n";
    for (st = v.begin(); st != it; ++st)
        cout << *st << ",";
    cout << '\n';

    return 0;
}