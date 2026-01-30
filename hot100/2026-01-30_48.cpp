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
    int pathSum(TreeNode* root, int targetSum) {
        vector<long> arr;
        return helper(root, targetSum, arr);
    }

    int helper(TreeNode* root, int targetSum, vector<long> &arr) {
        if (root == nullptr) {
            return 0;
        }
        int ans = 0;
        for (int i = 0; i < arr.size(); ++i) {
            arr[i] = arr[i] + root->val;
            ans += arr[i] == targetSum;
        }
        arr.push_back(root->val);
        ans += root->val == targetSum;
        ans += helper(root->left, targetSum, arr);
        ans += helper(root->right, targetSum, arr);
        arr.pop_back();
        for (int i = 0; i < arr.size(); ++i) {
            arr[i] -= root->val;
        }
        return ans;
    }
};