#include <vector>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (nums[m] < nums[n - 1]) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return nums[l];
    }
};