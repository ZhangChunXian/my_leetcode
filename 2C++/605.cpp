#include <vector>
using namespace std;

/**
 * @brief 不知道什么时候写的
 * 执行用时：28 ms, 在所有 C++ 提交中击败了7.02%的用户
 * 内存消耗：19.8 MB, 在所有 C++ 提交中击败了43.10%的用户通过测试用例：124 / 124
 */
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


/**
 * @brief 统一连续0的数量
 * 执行用时：8 ms, 在所有 C++ 提交中击败了97.64%的用户
 * 内存消耗：19.8 MB, 在所有 C++ 提交中击败了23.27%的用户
 */
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(flowerbed.size() == 0) return n == 0;

        int countOfZero = 1;    // 当前全0区段中连续0的数量, 刚开始预设1个0, 因为开头花坛的最左边没有花, 可以认为存在一个虚无的0
        int canPlace = 0;       // 可以种的花的数量

        for(int bed : flowerbed) {
            if (bed == 0) { // 遇到0, 连续0的数量+1
                countOfZero++;
            } else {    // 遇到1, 结算上一区段连续的0区间
                canPlace += (countOfZero - 1) / 2;
                if (canPlace >= n) return true;
                countOfZero = 0;
            }
        }

        // 最后一段0还未结算
        countOfZero++;
        canPlace += (countOfZero - 1) / 2;

        return canPlace >= n;
    }
};

