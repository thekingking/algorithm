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
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int all = 0;
        for (const int &x : nums) {
            all += x;
        }
        if (all % 2 != 0) {
            return false;
        }
        unordered_set<int> set{0};
        for (const int &x : nums) {
            vector<int> arr{x};
            for (const int &s : set) {
                if (s + x == all / 2) {
                    return true;
                }
                if (set.find(s + x) == set.end() && s + x < all / 2) {
                    arr.push_back(s + x);
                }
            }
            for (const int &a : arr) {
                set.insert(a);
            }
        }
        return false;
    }
};