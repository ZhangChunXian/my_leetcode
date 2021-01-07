#include "cpp_header.h"
/**
 * @brief 2021年1月7日 14:15:26 费了老大劲独立做出来了
 * 执行用时：16 ms, 在所有 C++ 提交中击败了42.89%的用户
 * 内存消耗：15.2 MB, 在所有 C++ 提交中击败了5.00%的用户
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *ptrl1 = l1, *ptrl2 = l2;
        ListNode *res = new ListNode(), *p = res;


        if (l1 == NULL) return l2;
        else if (l2 == NULL) return l1;

        while (ptrl1 != NULL && ptrl2 != NULL) {
            if (ptrl1->val > ptrl2->val) {
                ListInsert(p, ptrl2->val);
                ptrl2 = ptrl2->next;
                p = p->next;
            }else {
                ListInsert(p, ptrl1->val);
                ptrl1 = ptrl1->next;
                p = p->next;
            }
        }

        while (ptrl1 != NULL) {
            ListInsert(p, ptrl1->val);
            ptrl1 = ptrl1->next;
            p = p->next;
        }

        while (ptrl2 != NULL) {
            ListInsert(p, ptrl2->val);
            ptrl2 = ptrl2->next;
            p = p->next;
        }

        return res->next;
    }

    void ListInsert(ListNode* node, int InsertElem) {
        ListNode *p = new ListNode(InsertElem);

        if (node != NULL) {
            p->next = node->next;
            node->next = p;
        }
    }
};