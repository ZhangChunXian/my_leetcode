/* 输入一棵二叉树的根节点，求该树的深度。
从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，
最长路径的长度为树的深度。
例如：
给定二叉树 [3,9,20,null,null,15,7]，
返回它的最大深度 3 
 */

#include "cpp_header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* 深度优先遍历法 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return max(left + 1, right + 1);
    }
};

/* 广度优先遍历法 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 1; i <= size; i++) {
                TreeNode* node = q.front();
                if (node->left)   q.push(node->left);
                if (node->right)  q.push(node->right);

                q.pop();
            }

            depth++;
        }

        return depth;
    }
};