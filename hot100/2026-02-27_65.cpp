#include <vector>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) {
            return {-1, -1};
        }
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (nums[l] != target) {
            return {-1, -1};
        }
        int left = l, right = l;
        while (right + 1 < n && nums[right + 1] == target) {
            right++;
        }
        return {left, right};
    }
};