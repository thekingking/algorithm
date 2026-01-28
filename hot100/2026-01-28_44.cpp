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

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if (root == nullptr) {
            return 0;
        }
        int count = k;
        return search(root, k);
    }

    int search(TreeNode* root, int &count) {
        if (root == nullptr) {
            return 0;
        }
        int res = search(root->left, count);
        if (count == 0) {
            return res;
        }
        count--;
        if (count == 0) {
            return root->val;
        }
        return search(root->right, count);
    }
};