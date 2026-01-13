#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<int> start(10001);
        vector<int> end(10001);
        vector<vector<int>> res;
        for (const auto &list : intervals) {
            start[list[0]]--;
            end[list[1]]++;
        }
        for (int r = 0, count = 0, l = 0; r <= 10000; ++r) {
            if (count == 0 && start[r] != 0) {
                l = r;
            }
            count += start[r] + end[r];
            if (count == 0 && end[r] != 0) {
                res.push_back({l, r});
            }
        }
        return res;
    }
};