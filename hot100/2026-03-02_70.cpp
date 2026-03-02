#include <vector>
#include <string>
#include <climits>
#include <stack>

using namespace std;

class MinStack {
private:
    stack<long long> val_stack;
    long long min_val;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (val_stack.empty()) {
            val_stack.push(0);
            min_val = val;
        } else {
            long long diff = val - min_val;
            val_stack.push(diff);
            if (diff < 0) {
                min_val = val;
            }
        }
    }
    
    void pop() {
        long long val = val_stack.top();
        val_stack.pop();
        if (val < 0) {
            min_val -= val;
        }
    }
    
    int top() {
        long long top = val_stack.top();
        return top < 0 ? min_val : min_val + top;
    }
    
    int getMin() {
        return  (int)min_val;
    }
};
