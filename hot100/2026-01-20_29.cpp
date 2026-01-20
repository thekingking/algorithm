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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p1 = head;
        ListNode *p2 = head;
        for (int i = 0; i <= n; ++i) {
            if (p2 == nullptr) {
                return head->next;
            }
            p2 = p2->next;
        }
        while(p2 != nullptr) {
            p1 = p1->next;
            p2 = p2->next;
        }
        if (p1->next != nullptr) {
            p1->next = p1->next->next;
        }
        return head;
    }
};