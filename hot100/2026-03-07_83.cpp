#include <vector>
#include <string>
#include <climits>
#include <stack>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int cur = 0, pre = 0;
        for (const int &x : nums) {
            int tmp = cur;
            cur = max(cur, pre + x);
            pre = tmp;
        }
        return max(pre, cur);
    }
};