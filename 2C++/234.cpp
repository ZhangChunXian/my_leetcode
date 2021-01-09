#include "cpp_header.h"
/**
 * @brief 2021年1月9日 09:41:04 独立做出, 将链表转化为普通数组做
 * 执行用时：32 ms, 在所有 C++ 提交中击败了58.78%的用户
 * 内存消耗：14.7 MB, 在所有 C++ 提交中击败了22.27%的用户
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;

        vector<int> temp;

        /* 确定链表的长度 */
        int LinkLength = 0;

        while (head != NULL) {
            LinkLength++;
            temp.push_back(head->val);
            head = head->next;
        }

        for (int i = 0, j = LinkLength - 1; i < j; i++, j--) {
            if (temp[i] != temp[j]) return false;
        }

        return true;

    }
};

/**
 * @brief 官方题解 利用递归解题
 * 
 */
class Solution {
    ListNode *frontPointer;
public:
    bool recursivelyCheck(ListNode *currentNode) {
        if (currentNode != nullptr) {
            if (!recursivelyCheck(currentNode->next)) {
                return false;
            }
            if (currentNode->val != frontPointer->val) {
                return false;
            }

            frontPointer = frontPointer->next;
        }
        return true;
    }

    bool isPalindrome(ListNode *head) {
        frontPointer = head;
        return recursivelyCheck(head);
    }
};