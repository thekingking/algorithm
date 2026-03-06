#include <vector>
#include <string>
#include <climits>
#include <stack>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int pre = 0, cur = 1;
        for (int i = 0; i < n; ++i) {
            cur = cur + pre;
            pre = cur - pre;
        }
        return cur;
    }
};