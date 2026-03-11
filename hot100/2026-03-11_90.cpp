#include <vector>
#include <string>
#include <climits>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp;
        int ans = 0;
        int idx = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                dp.push_back(min(idx, i));
                idx = i + 1;
            } else if (dp.size() > 0) {
                ans = max(ans, i - dp.back() + 1);
                idx = dp.back();
                dp.pop_back();
            } else {
                idx = i + 1;
            }
        }
        return ans;
    }
};