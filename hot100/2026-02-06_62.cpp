#include <vector>
#include <string>
#include <climits>

using namespace std;

class Solution {
private:
    vector<vector<string>> ans;
    vector<string> ret;
    vector<bool> cols;
    vector<bool> f1;
    vector<bool> f2;
public:
    vector<vector<string>> solveNQueens(int n) {
        cols = vector<bool>(n, false);
        f1 = vector<bool>(2 * n, false);
        f2 = vector<bool>(2 * n, false);
        helper(n, 0);
        return ans;
    }

    void helper(int n, int idx) {
        if (n == idx) {
            ans.push_back(ret);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (!cols[i] && !f1[idx + i] && !f2[n + idx - i - 1]) {
                string s;
                for (int j = 0; j < n; ++j) {
                    if (j == i) {
                        s.push_back('Q');
                    } else {
                        s.push_back('.');
                    }
                }
                ret.push_back(s);
                cols[i] = true;
                f1[idx + i] = true;
                f2[n + idx - i - 1] = true;
                helper(n, idx + 1);
                ret.pop_back();
                cols[i] = false;
                f1[idx + i] = false;
                f2[n + idx - i - 1] = false;
            }
        }
    }
};