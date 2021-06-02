/* 给定一个二叉树，检查它是否是镜像对称的。
例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
*/

#include "cpp_header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* 递归方法 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }

    bool check(TreeNode *p, TreeNode *q) {
        // p, q同时为空, 则真
        if (!p && !q) return true;
        // p, q仅有一个为空, 则假
        if (!p || !q) return false;

        return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
    }
};