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
private:
    vector<vector<int>> word = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {9, 10, 11}, {12, 13, 14}, 
                            {15, 16, 17, 18}, {19, 20, 21}, {22, 23, 24, 25}};
public:
    vector<string> letterCombinations(string digits) {
        return helper({}, digits, 0);
    }

    vector<string> helper(string path, string &digits, int idx) {
        if (idx == digits.size()) {
            return {path};
        }
        vector<string> ans;
        char c = digits[idx];
        for (const int w : word[c - '2']) {
            string nextPath = path;
            nextPath.push_back(w + 'a');
            vector<string> list = helper(nextPath, digits, idx + 1);
            ans.insert(ans.end(), move_iterator(list.begin(), list.end()));
        }
        return ans;
    }
};