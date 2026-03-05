#include <vector>
#include <string>
#include <climits>
#include <stack>
#include <unordered_map>
#include <queue>

using namespace std;

class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int>> queMin;
    priority_queue<int, vector<int>, greater<int>> queMax;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (queMin.empty() || num <= queMin.top()) {
            queMin.push(num);
            if (queMax.size() + 1 < queMin.size()) {
                queMax.push(queMin.top());
                queMin.pop();
            }
        } else {
            queMax.push(num);
            if (queMin.size() < queMax.size()) {
                queMin.push(queMax.top());
                queMax.pop();
            }
        }
    }
    
    double findMedian() {
        if (queMin.size() > queMax.size()) {
            return queMin.top();
        }
        return (queMax.top() + queMin.top()) / 2.0;
    }
};

