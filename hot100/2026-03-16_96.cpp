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
    int singleNumber(vector<int>& nums) {
        int val = 0;
        for (const int &x: nums) {
            val ^= x;
        }
        return val;
    }
};