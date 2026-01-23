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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return splitLists(lists, 0, lists.size() - 1);
    }

    ListNode* splitLists(vector<ListNode*>& lists, int l, int r) {
        if (l > r) {
            return nullptr;
        } else if (l == r) {
            return lists[l];
        } 
        int mid = (l + r) / 2;
        return mergeLists(splitLists(lists, l, mid), splitLists(lists, mid + 1, r));
    }

    ListNode* mergeLists(ListNode *left, ListNode *right) {
        ListNode dumpy(0);
        ListNode *p = &dumpy;
        while (left && right) {
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
        if (left) {
            p->next = left;
        }
        if (right) {
            p->next = right;
        }
        return dumpy.next;
    }
};