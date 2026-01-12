#include <vector>
#include <string>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <deque>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> count(128);
        int m = s.size();
        int n = t.size();
        if (m < n) {
            return "";
        }
        int num = 0;
        int start = 0;
        int len = m + 1;
        for (int i = 0; i < n; ++i) {
            count[t[i]]--;
            num--;
        }
        for (int l = 0, r = 0; r < m; ++r) {
            if (count[s[r]] < 0) {
                num++;
            }
            count[s[r]]++;
            while(num == 0 && l <= r) {
                if (r - l < len) {
                    len = r - l + 1;
                    start = l;
                }
                count[s[l]]--;
                if (count[s[l]] < 0) {
                    num--;
                }
                l++;
            }
        }
        if (len > m) {
            return "";
        }
        return s.substr(start, len);
    }
};