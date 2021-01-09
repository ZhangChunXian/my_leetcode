#include "cpp_header.h"
/**
 * @brief 2021年1月9日 10:07:27 独立做出, 利用快慢指针法
 * 执行用时：8 ms, 在所有 C++ 提交中击败了93.50%的用户
 * 内存消耗：7.9 MB, 在所有 C++ 提交中击败了29.72%的用户
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return false;

        ListNode *SlowPtr = head, *QuickPtr = head->next;
        int count = 0;

        while (QuickPtr != NULL) {
            count++;

            QuickPtr = QuickPtr->next;
            if (count % 2 == 0) {
                SlowPtr = SlowPtr->next;
            }

            if (SlowPtr == QuickPtr) {
                return true;
            }
        }

        return false;
    }
};

/**
 * @brief 官方题解, 利用哈希表
 * 执行用时：28 ms, 在所有 C++ 提交中击败了9.24%的用户
 * 内存消耗：9.7 MB, 在所有 C++ 提交中击败了10.05%的用户
 */
class Solution {
    public:
        bool hasCycle(ListNode *head) {
            unordered_set<ListNode*> seen;

            while (head != nullptr) {
                if (seen.count(head)) {
                    return true;
                }

                seen.insert(head);
                head = head->next;
            }

            return false;
        }
};