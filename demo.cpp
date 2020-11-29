#include <iostream>
#include <numeric>

using namespace std;


int myfun(int x, int y)
{
    return x * y;
}


bool isShorter(const string &s1, const string &s2)
{
    return s1.size < s2.size;
}

int main()
{
    stable_sort(words.begin(), words.end(), isShorter)
}