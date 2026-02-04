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
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> flags(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (helper(board, flags, word, i, j, 0, m, n)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool helper(vector<vector<char>>& board, vector<vector<bool>>& flags, string& word, int i, int j, int k, int m, int n) {
        if (k == word.size()) {
            return true;
        }
        if (i < 0 || i >= m || j < 0 || j >= n || flags[i][j] || board[i][j] != word[k]) {
            return false;
        }
        flags[i][j] = true;
        bool ans =  helper(board, flags, word, i + 1, j, k + 1, m, n)
                 || helper(board, flags, word, i - 1, j, k + 1, m, n)
                 || helper(board, flags, word, i, j + 1, k + 1, m, n)
                 || helper(board, flags, word, i, j - 1, k + 1, m, n);
        flags[i][j] = false;
        return ans;
    }
};