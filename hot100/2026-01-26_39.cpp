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
    int diameterOfBinaryTree(TreeNode* root) {
        int depth = 0;
        return root == nullptr ? 0 : max(maxDepth(root->left, depth) + maxDepth(root->right, depth), depth);
    }

    int maxDepth(TreeNode* root, int &depth) {
        if (root == nullptr) {
            return 0;
        }
        int left = maxDepth(root->left, depth);
        int right = maxDepth(root->right, depth);
        depth = max(left + right, depth);
        return max(left, right) + 1;
    }
};