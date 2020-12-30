#include "cpp_header.h"

int main() {
    // // get an iterator to an element in word_count
    // auto map_it = word_count.begin();
    // // *map_it is a reference to a pair <const string, size_t> object
    // cout << map_it->first;      // print the key for this elemnet
    // cout << " " << map_it->second;  // print the value of the element

    // set<int> iset = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // set<int>::iterator set_it = iset.begin();
    // if (set_it != iset.end()) {
    //     *

    // vector<int> ivec = {2, 4, 6, 8, 2, 4, 6, 8};
    // set<int> set2;
    // set2.insert(ivec.begin(), ivec.end());      // set2 has four elements
    // set2.insert({1, 3, 5, 7, 1, 3, 5, 7});
    // map<string, size_t> word_count;
    // string word;
    // while (cin >> word)
    //     ++word_count[word];

    // for (const auto &w : word_count) {
    //     cout << w.first << "occurs" << w.second
    //     << ((w.second > 1) ? " times" : "time") << endl;
    // }

    // // four ways to add word to word_count
    // word_count.insert({word, 1});
    // word_count.insert(make_pair(word, 1));
    // word_count.insert(pair<string, size_t>(word, 1));
    // word_count.insert(map<string, size_t>::value_type(word, 1));

    // more verbose way to count number of times each word occurs in the input
    map<string, size_t> word_count;     // empty map from string to size_t
    string word;

    while (cin >> word) {
        // inserts an element with key equal to word and value 1;
    }
}

