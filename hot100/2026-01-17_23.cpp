#include <vector>
#include <string>
#include <climits>
#include <algorithm>
#include <unordered_map>
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
    ListNode* reverseList(ListNode* head) {
        ListNode* node = nullptr;
        ListNode* cur;
        while(head != nullptr) {
            cur = head;
            head = head->next;
            cur->next = node;
            node = cur;
        }
        return node;
    }
};