#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int pre = 0;
        for (const auto &x : nums) {
            pre = max(pre + x, x);
            res = max(pre, res);
        }
        return res;
    }
};