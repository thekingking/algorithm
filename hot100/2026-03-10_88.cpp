#include <vector>
#include <string>
#include <climits>
#include <stack>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int ans = 0;
        int neg = 0, pos = 0;
        for (const int& x : nums) {
            int p = pos, n = neg;
            if (x > 0) {
                pos = max(x, x * p);
                neg = min(0, x * n);
            } else if (x < 0) {
                neg = min(x, x * p);
                pos = max(0, x * n);
            } else {
                pos = 0;
                neg = 0;
            }
            ans = max(pos, ans);
        }
        return ans;
    }
};