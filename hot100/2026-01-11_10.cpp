#include <vector>
#include <string>
#include <climits>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int res = 0, pre = 0;
        for (auto &x : nums) {
            pre += x;
            if (mp.find(pre - k) != mp.end()) {
                res += mp[pre - k];
            }
            mp[pre]++;
        }
        return res;
    }
};