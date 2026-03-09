#include <vector>
#include <string>
#include <climits>
#include <stack>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> arr(n + 1, false);
        arr[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (const string &word : wordDict) {
                int l = word.size();
                if (i < l || s.compare(i - l, l, word) != 0) {
                    continue;
                }
                arr[i] = arr[i] || arr[i - l];
            }
        }
        return arr[n];
    }
};