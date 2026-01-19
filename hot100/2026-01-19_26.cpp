#include <climits>
#include <unordered_set>

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
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> set;
        ListNode *p = head;
        while (head != nullptr && set.count(p) == 0) {
            set.insert(p);
            p = p->next;
        }
        return p;
    }
};