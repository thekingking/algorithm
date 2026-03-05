#include <vector>
#include <string>
#include <climits>
#include <stack>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int num = 1;
        for (int i = 0; i < nums.size() - 1; ++i) {
            num = max(num - 1, nums[i]);
            if (num == 0) {
                return false;
            }
        }
        return true;
    }
};