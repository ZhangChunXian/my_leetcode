#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        int i = 0;
        int FlowerMax = 0;

        if (n == 0) return true;
        if (size == 1 && n <= 1) {
            if (flowerbed[0] == 0) return true;
            else return false;
        } else if (size == 2 && n <= 2) {
            if (flowerbed[0] == 0 && flowerbed[1] == 0 && n == 1) return true;
            else return false;
        }
        for(; i < size - 2; i++) {
            if (i == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
                FlowerMax++;
                flowerbed[i] = 1;
            } else if (flowerbed[i] == 0 && flowerbed[i + 1] == 0 && flowerbed[i + 2] == 0 && i < size - 3) {
                FlowerMax++;
                flowerbed[i + 1] = 1;
            }
            if (i == size - 3 && flowerbed[i + 1] == 0 && flowerbed[i + 2] == 0) {
                FlowerMax++;
                flowerbed[i + 2] = 1;
            }
        }

        if (FlowerMax < n) return false;
        else return true;
    }
};