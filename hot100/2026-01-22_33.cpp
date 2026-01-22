#include <vector>
#include <string>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <deque>

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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode dumpy(0, head);
        
        ListNode *p = &dumpy;
        ListNode *q = &dumpy;
        while (q != nullptr && q->next != nullptr) {
            p = p->next;
            q = q->next->next;
        }
        ListNode *right = sortList(p->next);
        p->next = nullptr;
        ListNode *left = sortList(head);
        
        ListNode ans(0);
        p = &ans;
        while (left != nullptr && right != nullptr) {
            if (left->val < right->val) {
                ListNode *tmp = left;
                left = left->next;
                tmp->next = p->next;
                p->next = tmp;
            } else {
                ListNode *tmp = right;
                right = right->next;
                tmp->next = p->next;
                p->next = tmp;
            }
            p = p->next;
        }
        if (left != nullptr) {
            p->next = left;
        }
        if (right != nullptr) {
            p->next = right;
        }
        return ans.next;
    }
};