#include "cpp_header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/**
 * @brief 2021年1月5日 20:50:17 独立做出, 将链表值交换, 释放已知节点后面的节点
 * 执行用时：12 ms, 在所有 C++ 提交中击败了92.12%的用户
 * 内存消耗：8.1 MB, 在所有 C++ 提交中击败了23.50%的用户
 */
class Solution {
public:
    void deleteNode(ListNode *node) {
        swap(node->val, node->next->val);

        ListNode *temp = node->next;
        node->next = node->next->next;
        delete(temp);
    }
};