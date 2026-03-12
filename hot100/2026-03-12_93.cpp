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
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<int> dp(m + 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0, p = 0; j < m; ++j) {
                int tmp = dp[j + 1];
                dp[j + 1] = max(dp[j], max(dp[j + 1], p + (int)(text1[i] == text2[j])));
                p = tmp;
            }
        }
        return dp[m];
    }
};