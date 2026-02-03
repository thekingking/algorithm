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
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        candidates.erase(std::unique(candidates.begin(), candidates.end()), candidates.end());
        return helper({}, candidates, 0, target);
    }

    vector<vector<int>> helper(vector<int> path, vector<int> &candidates, int idx, int target) {
        if (target == 0) {
            return {path};
        }
        vector<vector<int>> ans;
        for (int i = idx; i < candidates.size(); ++i) {
            if (candidates[i] <= target) {
                vector<int> nextPath = path;
                nextPath.push_back(candidates[i]);
                vector<vector<int>> list = helper(nextPath, candidates, i, target - candidates[i]);
                ans.insert(ans.end(), move_iterator(list.begin()), move_iterator(list.end()));
            }
        }
        return ans;
    }
};