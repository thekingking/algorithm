#include <vector>
#include <string>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <queue>
#include <list>
#include <stack>
#include <span>

using namespace std;

struct NodeList {
    int val;
    NodeList* children[26];
    NodeList() : val(0) {
        for (int i = 0; i < 26; ++i) children[i] = nullptr;
    }
};

class Trie {
private:
    NodeList* node;
public:
    Trie() {
        node = new NodeList();
    }
    
    void insert(string word) {
        NodeList* p = node;
        for (const char c : word) {
            if (p->children[c - 'a'] == nullptr) {
                p->children[c - 'a'] = new NodeList();
            }
            p = p->children[c - 'a'];
        }
        p->val = 1;
    }
    
    bool search(string word) {
        NodeList* p = node;
        for (const char c : word) {
            if (p->children[c - 'a'] == nullptr) {
                return false;
            }
            p = p->children[c - 'a'];
        }
        return p->val != 0;
    }
    
    bool startsWith(string prefix) {
        NodeList* p = node;
        for (const char c : prefix) {
            if (p->children[c - 'a'] == nullptr) {
                return false;
            }
            p = p->children[c - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */