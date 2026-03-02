#include <vector>
#include <string>
#include <climits>
#include <stack>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> num_stack;
        stack<string> str_stack;
        int n = 0;
        string str = "";
        for (char ch : s) {
            if (ch <= '9' && ch >= '0') {
                n = n * 10 + ch - '0';
            } else if (ch == '[') {
                num_stack.push(n);
                n = 0;
                str_stack.push(str);
                str = "";
            } else if (ch == ']') {
                int num = num_stack.top();
                num_stack.pop();
                string pre = str_stack.top();
                str_stack.pop();
                for (int i = 0; i < num; ++i) {
                    pre += str;
                }
                str = pre;
            } else {
                str += ch;
            }
        }
        return str;
    }
};