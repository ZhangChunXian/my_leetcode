#include "cpp_header.h"
/**
 * @brief 看提示后独立做出 2021年1月7日 14:36:11
 * 执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
 * 内存消耗：7.9 MB, 在所有 C++ 提交中击败了13.72%的用户
*/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        if (head == NULL || head->next == NULL) return head;

        swap(head->val, head->next->val);

        head->next->next = swapPairs(head->next->next);

        return head;
    }
};