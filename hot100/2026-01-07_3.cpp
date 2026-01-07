#include <vector>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int res = 0;
        int count = 1;
        int num = nums[0];
        for (int i = 1; i < (int)nums.size(); ++i) {
            if (nums[i] == num) {
                continue;
            } else if (nums[i] == num + 1) {
                count++;
            } else {
                res = max(res, count);
                count = 1;
            }
            num = nums[i];
        }
        return max(res, count);
    }
};