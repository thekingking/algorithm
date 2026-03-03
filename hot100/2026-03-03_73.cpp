#include <vector>
#include <string>
#include <climits>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        vector<int> arr;
        for (int i = 0; i < heights.size(); ++i) {
            while (!arr.empty() && heights[arr.back()] >= heights[i]) {
                arr.pop_back();
            }
            arr.push_back(i);
            for (int j = 0, pre = -1; j < arr.size(); ++j) {
                ans = max(ans, (i - pre) * heights[arr[j]]);
                pre = arr[j];
            }
        }
        return ans;
    }
};