// Program below illustrates the 
// vector::insert() function 
  
#include <bits/stdc++.h> 
using namespace std; 
  
int main() 
{ 
    // initialising the vector 
    vector<int> vec = { 10, 20, 30, 40 }; 
  
    // inserts 3 at front 
    auto it = vec.insert(vec.begin(), 3); 
    // inserts 2 at front 
    vec.insert(it, 2); 
  
    int i = 2; 
    // inserts 7 at i-th index 
    it = vec.insert(vec.begin() + i, 7); 

    cout << "The vector elements are: "; 
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        // *it = *it + 1;
        cout << *it << " ";
    }
  
    return 0; 
} 