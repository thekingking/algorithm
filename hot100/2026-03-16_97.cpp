#include <vector>
#include <string>
#include <climits>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int val = nums[0], count = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (count == 0) {
                val = nums[i];
            }
            count += val == nums[i] ? 1 : -1;
        }
        return val;
    }
};