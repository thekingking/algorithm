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
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n, 0);
        for (const int &x : nums) {
            count[x] += 1;
        }
        for (int i = 0; i < n; ++i) {
            if (count[i] > 1) {
                return i;
            }
        }
        return n;
    }
};