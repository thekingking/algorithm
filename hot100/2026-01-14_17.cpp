#include <vector>
#include <string>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <deque>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        vector<int> count(n + 1);
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0 && nums[i] <= n) {
                count[nums[i] - 1]++;
            }
        }
        for (int i = 0; i <= n; ++i) {
            if (count[i] == 0) {
                res = i + 1;
                break;
            }
        }
        return res;
    }
};