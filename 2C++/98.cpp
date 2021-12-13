#include "cpp_header.h"

/**
 * @brief 官方题解 递归解法
 * 执行用时：16 ms, 在所有 C++ 提交中击败了38.24%的用户
 * 内存消耗：21 MB, 在所有 C++ 提交中击败了90.36%的用户
 */
class Solution {
public:
    bool helper(TreeNode* root, long long lower, long long upper) {
        if (root == NULL) return true;
        if (root->val <= lower || root->val >= upper) {
            return false;
        }
        return helper(root->left, lower, root->val) && helper(root->right, root->val, upper);
    }

    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
};

/**
 * @brief 官方题解 中序遍历(迭代版)
 * 执行用时：16 ms, 在所有 C++ 提交中击败了38.24%的用户内存消耗：21.3 MB, 在所有 C++ 提交中击败了23.78%的用户
 */

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stack;
        long long inorder = (long long)INT_MIN - 1;

        while(!stack.empty() || root != nullptr) {
            while(root != nullptr) {
                stack.push(root);
                root = root->left;
            }
            root = stack.top();
            stack.pop();
            // 如果中序遍历得到的节点的值小于等于前一个inorder, 说明不是二叉搜索树
            if (root->val <= inorder) {
                return false;
            }
            inorder = root->val;
            root = root->right;
        }
        return true;
    }
};