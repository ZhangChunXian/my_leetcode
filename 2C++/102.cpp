#include "cpp_header.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (!root) {
            return ret;
        }

        // 初始化一个辅助队列
        queue<TreeNode*> q;

        // 根节点入队
        q.push(root);

        // 若队列非空, 则对头结点出队, 访问该结点, 并将其左右孩子插入队尾(如果有的话)
        while (!q.empty()) {        // 若队列非空
            int currentLevelSize = q.size();
            vector<int> temp;

            for (int i = 1; i <= currentLevelSize; i++) {
                auto node = q.front();
                q.pop();           // 对头结点出队
                temp.push_back(node->val); // 访问该结点

                // 并将其左右孩子插入队尾(如果有的话)
                if (node->left )  q.push(node->left);
                if (node->right)  q.push(node->right);
            }
            ret.push_back(temp);
        }

        return ret;
    }
};