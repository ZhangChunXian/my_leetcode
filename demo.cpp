#include <iostream>
#include <string>
using namespace std;

void find_first_not_ofDemo(string str1, string str2) {
    string::size_type ch = str1.find_first_not_of(str2);
    cout << "First unmatched character :";
    cout << str1[ch];
}

// Driver code
int main() {
    _int128 
}