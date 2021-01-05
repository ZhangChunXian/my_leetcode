#include "cpp_header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode *next) : val(val), next(next) {}
};
/**
 * @brief 题目额外要求: 只用一遍遍历就解出
 * 第一遍解法先用两遍遍历的方法, 2021年1月5日 21:14:19 个人独立写出
 * 执行用时：8 ms, 在所有 C++ 提交中击败了61.83%的用户
 * 内存消耗：11 MB, 在所有 C++ 提交中击败了5.91%的用户
 */


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /* 求链表的长度 */
        int ListLength = 0;
        ListNode* cur = head;
        while (cur != NULL) {
            ListLength++;
            cur = cur->next;
        }
        /* 考虑下特殊情况 */
        if (ListLength == 1 && n == 1) return NULL;
        /* 如果删除的节点是第一个结点 */
        if (n == ListLength) {
            ListNode* temp = head->next;
            delete(head);
            return temp;
        }

        cur = head;
        /* 循环到待删除数组前一个链表 */
        for (int i = 1; i < ListLength - n; i++) {
            cur = cur->next;
        }

        ListNode* temp = cur->next;     // 待删除结点
        cur->next = cur->next->next;
        delete(temp);
        return head;
    }
};