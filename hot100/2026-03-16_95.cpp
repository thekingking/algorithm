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
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int> dp(m + 1, m);
        for (int i = 0; i < m; ++i) {
            dp[i] = i;
        }
        for (int i = 0; i < n; ++i) {
            int p = dp[0];
            ++dp[0];
            for (int j = 0; j < m; ++j) {
                int tmp = dp[j + 1];
                dp[j + 1] = min(dp[j] + 1, min(dp[j + 1] + 1, p + (int)(word1[i] != word2[j])));
                p = tmp;
            }
        }
        return dp[m];
    }
};