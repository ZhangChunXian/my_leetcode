#include <bitset>
#include <iostream>
using namespace std;

#define M 32

int main() {
    // default constructor initializes with all bits 0
    bitset<M> bset1;

    // bset2 is initialized with bits of 20
    bitset<M> bset2(20);

    bitset<M> bset3(string("1100"));

    cout << bset1 << endl;
    cout << bset2 << endl;
    cout << bset3 << endl;

    bitset<8> set8;

    set8[1] = 1;
    set8[4] = set8[1];

    cout << set8 << endl;

    int numberof1 = set8.count();

    cout << numberof1 << endl;

    cout << set8.any() << endl;

    cout << set8.set() << endl;
    cout << set8.set(4, 0) << endl;

    cout << set8.reset() << endl;
}