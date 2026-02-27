#include <vector>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) {
            return -1;
        }
        if (nums[n - 1] > target) {
            int l = 0, r = n - 1;
            while (l <= r) {
                int m = (l + r) / 2;
                if (nums[m] >= nums[n - 1] || nums[m] < target) {
                    l = m + 1;
                } else if (nums[m] > target) {
                    r = m - 1;
                } else {
                    return m;
                }
            }
        } else if (nums[n - 1] < target) {
            int l = 0, r = n - 1;
            while (l <= r) {
                int m = (l + r) / 2;
                if (nums[m] <= nums[n - 1] || nums[m] > target) {
                    r = m - 1;
                } else if (nums[m] < target) {
                    l = m + 1;
                } else {
                    return m;
                }
            }
        } else {
            return n - 1;
        }
        return -1;
    }
};