
class Solution {
public:
    int findrepeatNumber(vector<int>& nums) {
        unordered_map<int, bool> map;

        for(int num : nums) {
            if(map[num]) return map;
            map[num] = true;
        }

        return -1;
    }
};