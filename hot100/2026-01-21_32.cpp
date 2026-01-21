#include <vector>
#include <string>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <deque>

using namespace std;

// Definition for singly-linked list.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> map;
        Node dumpy(0);
        Node* p = &dumpy;
        Node* q = head;
        while (q != nullptr) {
            p->next = new Node(q->val);
            map[q] = p->next;
            p = p->next;
            q = q->next;
        }
        p = dumpy.next;
        q = head;
        while (q != nullptr) {
            if (q->random != nullptr) {
                p->random = map.at(q->random);
            }
            p = p->next;
            q = q->next;
        }
        return dumpy.next;
    }
};