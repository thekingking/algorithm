#include <vector>
#include <string>
#include <climits>
#include <stack>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26);
        vector<int> ans;
        for (int i = 0; i < s.size(); ++i) {
            last[s[i] - 'a'] = i;
        }
        for (int i = 0, end = 0, pre = -1; i < s.size(); ++i) {
            end = max(last[s[i] - 'a'], end);
            if (end <= i) {
                ans.push_back(i - pre);
                pre = i;
            }
        }
        return ans;
    }
};