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
    ListNode* swapPairs(ListNode* head) {
        ListNode dumpy(0, head);
        ListNode *p = &dumpy;
        while (p->next != nullptr && p->next->next != nullptr) {
            ListNode *tmp = p->next;
            p->next = p->next->next;
            tmp->next = p->next->next;
            p->next->next = tmp;
            p = p->next->next;
        }
        return dumpy.next;
    }
};