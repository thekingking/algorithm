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
    string longestPalindrome(string s) {
        int n = s.size();
        int l = 0, r = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; i - j >= 0 && i + j < n; ++j) {
                if (s[i - j] == s[i + j]) {
                    if (2 * j + 1 > r - l + 1) {
                        l = i - j;
                        r = i + j;
                    }
                } else {
                    break;
                }
            }
            for (int j = 0; i - j >= 0 && i + j + 1 < n; ++j) {
                if (s[i - j] == s[i + j + 1]) {
                    if (2 * (j + 1) > r - l + 1) {
                        l = i - j;
                        r = i + j + 1;
                    }
                } else {
                    break;
                }
            }
        }
        return s.substr(l, r - l + 1);
    }
};