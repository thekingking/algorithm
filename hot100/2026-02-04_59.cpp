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
    vector<string> generateParenthesis(int n) {
        return helper({}, n, n);
    }

    vector<string> helper(string path, int l, int r) {
        if (l == 0 && r == 0) {
            return {path};
        }
        vector<string> ans;
        if (l > 0) {
            string lpath = path;
            lpath.push_back('(');
            vector<string> left = helper(lpath, l - 1, r);
            ans.insert(ans.end(), move_iterator(left.begin()), move_iterator(left.end()));
        }
        if (r > l) {
            string rpath = path;
            rpath.push_back(')');
            vector<string> right = helper(rpath, l, r - 1);
            ans.insert(ans.end(), move_iterator(right.begin()), move_iterator(right.end()));
        }
        return ans;
    }
};