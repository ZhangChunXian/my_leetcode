#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode *dummyhead = new ListNode(-1);         // 伪头指针
        dummyhead->next = head;
        ListNode *prev = head;             // prev永远指向已经排好序的尾结点
        ListNode *node = head->next;

        while (node) {      // 要插入的结点是node
            if (node->val < prev->val) {
                ListNode* temp = dummyhead;
                // 这里是temp->next需要注意以下, 比如1-3插入2, temp->next停在3上, temp是指在1上

                    while (temp->next->val < node->val) { // temp作用: 从头找到一个位置来插入node
                        temp = temp->next;  // 指针后移
                    }

                    // 因为实际操作还是在一个完整的链表上进行的
                    // (1) 所以每次要断链去除一个: 把要取出的node断开, 把node->next接上prev上

                    prev->next = node->next;

                    // (2) 把去取出的结点重新接在链表上, 分两步, 比如1->3插入2
                    node->next = temp->next; // (i) 第一步: 把1-3断链, 令2指向3
                    temp->next = node;      // (ii) 第二步: 把1-2接上, 令1指向2
                    // prev指向的是排好序之后的尾结点, prev->next作为下一次循环的node
                    node = prev->next;
            }
            else {  // 如果node值比排好序的尾结点值还大, 就不用操作, 直接检查一下个node
                    prev = prev->next;
                    node = node->next;
            }
        }
        delete dummyhead;
        return dummyhead->next;
    }
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
	    if (!head || !head->next) return head;
	    ListNode *dummyhead = new ListNode(-1);//伪头指针
	    dummyhead->next = head;
	    ListNode *prev = head; // prev永远指向已排好序的尾节点，断链之后把node后面的节点接在prev上
	    ListNode *node = head->next;
	    while (node){//要插入的节点是node
		    if (node->val < prev->val){
			    ListNode* temp = dummyhead;
			    //这里是temp->next需要注意一下，比如1-3插入2，temp->next停在3上，temp是指在1上
                while (temp->next->val < node->val){//temp作用:从头找到一个位置来插入node
				    temp = temp->next; //指针后移
			    }
                // 因为实际操作还是在一个完整的链表上进行的
                // （1）所以每次要断链取出一个：把要取出的node断开，把node->next接在prev上
			    prev->next = node->next;
                // （2）把取出的节点重新接在链表上，分两步：比如说1->3插入2
			    node->next = temp->next; // (i) 第一步: 把1-3断链，令2指向3
			    temp->next = node;// (ii) 第二步: 把1-2接上，令1指向2
                // prev指向的是排好序之后的尾结点，prev->next作为下一次循环的node
			    node = prev->next;
		    }
		    else{//如果node值比排好序的尾结点值还大，就不用操作，直接检查一下个node
			    prev = prev->next;
			    node = node->next;
		    }
	    }
	    return dummyhead->next;
    }
};