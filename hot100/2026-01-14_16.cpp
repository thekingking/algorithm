#include <vector>
#include <string>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        ans[0] = 1;
        for (int i = 1; i < n; ++i) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        for (int i = 0, r = 1; i < n; ++i) {
            ans[n - i - 1] = ans[n - i - 1] * r;
            r *= nums[n - i - 1];
        }
        return ans;
    }
};