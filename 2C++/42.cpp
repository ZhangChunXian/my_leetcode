#include "cpp_header.h"

/**
 * @brief 2021年1月11日 16:11:03 不是自己做的, 来不及了, 马上就考试了
 * 先抄一下
 * 执行用时：16 ms, 在所有 C++ 提交中击败了32.25%的用户
 * 内存消耗：9.6 MB, 在所有 C++ 提交中击败了21.02%的用户
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode *> visited;

        while (head != NULL) {
            if (visited.count(head)) {
                return head;
            }

            visited.insert(head);
            head = head->next;
        }

        return NULL;
    }
};