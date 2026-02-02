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
    vector<vector<int>> permute(vector<int>& nums) {
        return helper({}, nums);
    }

    vector<vector<int>> helper(vector<int> path, vector<int> remains) {
        if (remains.empty()) {
            return {path};
        }
        vector<vector<int>> ans;
        for (int i = 0; i < remains.size(); ++i) {
            vector<int> nextPath = path;
            nextPath.push_back(remains[i]);

            vector<int> nextRemains = remains;
            nextRemains.erase(nextRemains.begin() + i);
            
            vector<vector<int>> list = helper(nextPath, nextRemains);
            ans.insert(ans.end(), make_move_iterator(list.begin()), make_move_iterator(list.end())); 
        }
        return ans;
    }
};
