#include <vector>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int flag = 0;
        int res = 0;
        vector<int> flags(128);
        for (int left = 0, right = 0; right < s.size(); ++right) {
            while (flags[s[right]]) {
                flags[s[left]] = 0;
                ++left;
            }
            flags[s[right]] = 1;
            res = max(res, right - left + 1);
        } 
        return res;
    }
};