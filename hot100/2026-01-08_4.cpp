#include <vector>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx1 = 0;
        int idx2 = 0;
        for (; idx2 < nums.size(); ++idx2) {
            if (nums[idx2] != 0) {
                swap(nums[idx1], nums[idx2]);
                ++idx1;
            }
        }
    }
};