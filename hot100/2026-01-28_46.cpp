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
    void flatten(TreeNode* root) {
        helper(root);
    }

    TreeNode* helper(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        TreeNode* right = helper(root->right);
        root->right = right;
        TreeNode* left = helper(root->left);
        if (left) {
            root->left = nullptr;
            TreeNode* p = left;
            while (p->right != nullptr) {
                p = p->right;
            }
            p->right = root->right;
            root->right = left;
        }
        return root;
    }
};