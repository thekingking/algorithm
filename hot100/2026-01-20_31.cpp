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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dumpy(0, head);
        ListNode* p = &dumpy;
        while (p->next != nullptr) {
            ListNode* q = p->next;
            ListNode* first = p->next;
            ListNode* t = p->next;
            for (int i = 0; i < k; ++i) {
                if (t == nullptr) {
                    return dumpy.next;
                }
                t = t->next;
            }
            for (int i = 0; i < k && p->next != nullptr; ++i) {
                ListNode* tmp = q;
                q = q->next;
                tmp->next = p->next;
                p->next = tmp;
            }
            first->next = q;
            p = first;
        }
        return dumpy.next;
    }
};