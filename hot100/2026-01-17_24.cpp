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
    bool isPalindrome(ListNode* head) {
        ListNode *p1 = head;
        ListNode *p2 = head;
        vector<int> arr;
        while (p2 != nullptr && p2->next != nullptr) {
            arr.push_back(p1->val);
            p1 = p1->next;
            p2 = p2->next->next;
        }
        if (p2 != nullptr) {
            p1 = p1->next;
        }
        while(p1 != nullptr) {
            if (p1->val != arr.back()) {
                return false;
            }
            p1 = p1->next;
            arr.pop_back();
        }
        return true;
    }
};