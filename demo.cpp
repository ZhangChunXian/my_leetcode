
#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main()
{
    string s("some string");
    vector<int> v(10, 1);

    for (auto it = s.cbegin(); it != s.end() && !it->empty(); ++it) {
        cout << *it << endl;
    }

    return 0;
}