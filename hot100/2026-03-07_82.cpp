#include <vector>
#include <string>
#include <climits>
#include <stack>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> arr;
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; ++i) {
            arr.push_back(1);
            for (int j = i - 1; j > 0; --j) {
                arr[j] = arr[j] + arr[j - 1];
            }
            ans.push_back(arr);
        }
        return ans;
    }
};