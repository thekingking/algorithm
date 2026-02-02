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

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans = helper({}, nums, 0);
        return ans;
    }

    vector<vector<int>> helper(vector<int> path, vector<int> &nums, int idx) {
        if (idx == nums.size()) {
            return {path};
        }
        vector<vector<int>> ans;
        ans.push_back(path);
        for (int i = idx; i < nums.size(); ++i) {
            vector<int> nextPath = path;
            nextPath.push_back(nums[i]);
            vector<vector<int>> list = helper(nextPath, nums, i + 1);
            ans.insert(ans.end(), move_iterator(list.begin()), move_iterator(list.end()));
        }
        return ans;
    }
};