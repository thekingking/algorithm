#include <vector>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i + 2 < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                if (left > i + 1 && nums[left] == nums[left - 1]) {
                    ++left;
                    continue;
                }
                int num = nums[i] + nums[left] + nums[right];
                if (num == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    ++left;
                } else if (num < 0) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
        return result;
    }
};