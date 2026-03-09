#include <vector>
#include <string>
#include <climits>
#include <stack>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    count = max(dp[j], count);
                }
            }
            dp[i] = count + 1;
            ans = max(dp[i], ans);
        }
        return ans;
    }
};