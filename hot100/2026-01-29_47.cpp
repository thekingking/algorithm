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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        auto p = span<int>(preorder);
        auto i = span<int>(inorder);
        return helper(p.subspan(0), i.subspan(0));
    }

    TreeNode* helper(span<int> preorder, span<int> inorder) {
        if (preorder.size() == 0) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        int count = 0;
        while (count < inorder.size() && preorder[0] != inorder[count]) {
            ++count;
        }
        root->left = helper(preorder.subspan(1, count), inorder.subspan(0, count));
        root->right = helper(preorder.subspan(count + 1), inorder.subspan(count + 1));
        return root;
    }
};