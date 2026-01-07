#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        vector<bool> visited(strs.size(), false);
        for (int i = 0; i < (int)strs.size(); ++i) {
            if (visited[i]) continue;
            visited[i] = true;
            int count[26] = {0};
            for (char c : strs[i]) {
                count[c - 'a']++;
            }
            vector<string> group = {strs[i]};
            for (int j = i + 1; j < (int)strs.size(); ++j) {
                if (visited[j]) continue;
                int num[26] = {0};
                for (char c : strs[j]) {
                    num[c - 'a']++;
                }
                bool isAnagram = true;
                for (int k = 0; k < 26; ++k) {
                    if (count[k] != num[k]) {
                        isAnagram = false;
                        break;
                    }
                }
                if (isAnagram) {
                    visited[j] = true;
                    group.push_back(strs[j]);
                }
            }
            result.push_back(group);
        }
        return result;
    }
};