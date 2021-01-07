#include "cpp_header.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * @brief 2021年1月7日 13:16:08 独立做出, 但算法不是很好
 * 执行用时：28 ms, 在所有 C++ 提交中击败了12.92%的用户
 * 内存消耗：8.6 MB, 在所有 C++ 提交中击败了41.64%的用户
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        vector<int> stack;
        ListNode *p = head;


    while (p != NULL) {
        stack.insert(stack.begin(), p->val);
        p = p->next;
    }

    p = head;
    for (auto it = stack.begin(); it != stack.end(); it++) {
        p->val = *it;
        p = p->next;
    }

    return head;
}
};

/**
 * @brief 个人独立改良版 2021年1月7日 13:20:44 将insert函数改为了更快的push_back函数
 * 执行用时：8 ms, 在所有 C++ 提交中击败了90.47%的用户
 * 内存消耗：8.5 MB, 在所有 C++ 提交中击败了51.51%的用户
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        vector<int> stack;
        ListNode *p = head;

        if (p == NULL) return NULL;
        while (p != NULL) {
            stack.push_back(p->val);
            p = p->next;
        }

        p = head;
        for (auto it = stack.end() - 1; it >= stack.begin(); it--) {
            p->val = *it;
            p = p->next;
        }

        return head;
    }
};