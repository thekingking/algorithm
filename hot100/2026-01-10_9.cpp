#include <vector>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sLen = s.size();
        int pLen = p.size();
        if (sLen < pLen) {
            return {};
        }

        vector<int> sCount(26);
        vector<int> pCount(26);
        vector<int> res;
        for (int i = 0; i < pLen; ++i) {
            ++sCount[s[i] - 'a'];
            ++pCount[p[i] - 'a'];
        }

        if (sCount == pCount) {
            res.push_back(0);
        }

        for (int i = 0; i < sLen - pLen; ++i) {
            --sCount[s[i] - 'a'];
            ++sCount[s[i + pLen] - 'a'];
            if (sCount == pCount) {
                res.push_back(i + 1);
            }
        }
        return res;
    }
};