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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        search(root, 1, res);
        return res;
    }

    void search(TreeNode* root, int height, vector<int> &arr) {
        if (root == nullptr) {
            return;
        }
        if (height > arr.size()) {
            arr.push_back(root->val);
        }
        search(root->right, height + 1, arr);
        search(root->left, height + 1, arr);
    }
};