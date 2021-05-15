#include "cpp_header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) return result;

        queue<TreeNode*> queue;
        vector<int> temp;
        queue.push(root);
        temp.push_back(root->val);
        result.push_back(temp);

        while (!queue.empty()) {
            temp.clear();
            for(int i = queue.size(); i > 0; i--) {
                TreeNode* p = queue.front();
                queue.pop();
                if (p->left) {
                    temp.push_back(p->left->val);
                    queue.push(p->left);
                }
                if (p->right) {
                    temp.push_back(p->right->val);
                    queue.push(p->right);
                }

            }
            if (temp.size() != 0) {
                result.push_back(temp);
            }
        }
        return result;
    }
};