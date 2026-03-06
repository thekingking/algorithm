#include <vector>
#include <string>
#include <climits>
#include <stack>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0, m = 0; i < n - 1; i = m) {
            ++ans;
            if (i + nums[m] >= n - 1) {
                break;
            }
            for (int j = i + 1; j <= i + nums[i]; ++j) {
                if (nums[m] - j + m <= nums[j]) {
                    m = j;
                }
            }
        }
        return ans;
    }
};