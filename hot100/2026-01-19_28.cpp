#include <climits>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode node;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* p = &node;
        int add = 0;
        while (p1 != nullptr && p2 != nullptr) {
            p1->val = p1->val + p2->val + add;
            add = p1->val / 10;
            p1->val %= 10;
            p->next = p1;
            p = p->next;
            p1 = p1->next;
            p2 = p2->next;
            
        }
        while (p1 != nullptr) {
            p1->val += add;
            add = p1->val / 10;
            p1->val %= 10;
            p->next = p1;
            p = p->next;
            p1 = p1->next;
        } 
        while (p2 != nullptr) {
            p2->val += add;
            add = p2->val / 10;
            p2->val %= 10;
            p->next = p2;
            p = p->next;
            p2 = p2->next;
        }
        if (add != 0) {
            p->next = new ListNode(add);
        }
        return node.next;
    }
};