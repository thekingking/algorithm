#include <vector>
#include <string>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <queue>
#include <list>
#include <stack>
#include <span>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> arr(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2) {
                    search(grid, arr, i+1, j, n, m, 1);
                    search(grid, arr, i-1, j, n, m, 1);
                    search(grid, arr, i, j+1, n, m, 1);
                    search(grid, arr, i, j-1, n, m, 1);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1 && arr[i][j] == 0) {
                    return -1;
                }
                ans = max(ans, arr[i][j]);
            }
        }
        return ans;
    }

    void search(vector<vector<int>>& grid, vector<vector<int>>& arr, int i, int j, int n, int m, int k) {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != 1 || arr[i][j] != 0 && arr[i][j] < k) {
            return;
        }
        arr[i][j] = k;
        search(grid, arr, i+1, j, n, m, k+1);
        search(grid, arr, i-1, j, n, m, k+1);
        search(grid, arr, i, j+1, n, m, k+1);
        search(grid, arr, i, j-1, n, m, k+1);
    }
};