#include <vector>
#include <string>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        ans.reserve(m * n);
        int count = 0;
        for (int k = 0; k * 2 < m && k * 2 < n; ++k) {
            for (int j = k; j <= n - k - 1; ++j) {
                ans.push_back(matrix[k][j]);
            }
            for (int i = k + 1; i <= m - k - 1; ++i) {
                ans.push_back(matrix[i][n - k - 1]);
            }
            for (int j = n - k - 2; j > k && k < m - k - 1; --j) {
                ans.push_back(matrix[m - k - 1][j]);
            }
            for (int i = m - k - 1; i > k && k < n - k - 1; --i) {
                ans.push_back(matrix[i][k]);
            }
        }
        return ans;
    }
};