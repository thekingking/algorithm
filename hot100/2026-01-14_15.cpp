#include <vector>
#include <string>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <deque>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        for (int i = 0; i * 2 + 1 < n; ++i) {
            swap(nums[i], nums[n - i - 1]);
        }
        for (int i = 0; i * 2 + 1 < k; ++i) {
            swap(nums[i], nums[k - i - 1]);
        }
        for (int i = 0; i * 2 + k + 1 < n; ++i) {
            swap(nums[i + k], nums[n - i - 1]);
        }
    }
};