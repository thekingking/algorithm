#include <vector>
#include <string>
#include <climits>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } else {
                char l = st.top();
                st.pop();
                if (l == '(' && s[i] != ')' 
                 || l == '[' && s[i] != ']'
                 || l == '{' && s[i] != '}') {
                    return false;
                 }
            }
        }
        return st.empty();
    }
};