#include <vector>
#include <string>
#include <climits>
#include <stack>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int m = INT32_MAX;
        for (const int &p : prices) {
            ans = max(ans, p - m);
            m = min(m, p);
        }
        return ans;
    }
};
