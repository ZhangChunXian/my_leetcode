#include "cpp_header.h"

class Solution {
    int pre_idx;
    unordered_map<int, int> idx_map;

public:
    TreeNode* helper(int )


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || inorder.size() == 0) return nullptr;
        // 从前序遍历的第一个元素开始作为root
        pre_idx = 0;

        // 建立(元素, 下标)键值对对应的哈希表
        int idx = 0;
        for (auto& val : inorder) {
            idx_map[val] = idx++;
        }

        return helper()
    }
}