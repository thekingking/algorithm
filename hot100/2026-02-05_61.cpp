#include <vector>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        return helper(s, {}, 0);        
    }

    vector<vector<string>> helper(string& s, vector<string> path, int idx) {
        if (idx == s.size()) {
            return {path};
        }
        vector<vector<string>> ans;
        for (int i = idx; i <s.size(); ++i) {
            bool flag = true;
            for (int l = idx, r = i; l < r; ++l, --r) {
                if (s[l] != s[r]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                path.push_back(s.substr(idx, i - idx + 1));
                auto sub = helper(s, path, i + 1);
                path.pop_back();
                ans.insert(ans.end(), move_iterator(sub.begin()), move_iterator(sub.end()));
            }
        }
        return ans;
    }
};