#include <vector>
#include <string>
#include <climits>
#include <stack>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        unordered_map<int, int> counts;
        vector<int> ans;
        for (int x : nums) {
            counts[x]++;
        }
        for (auto const& [val, freq] : counts) {
            heap.push({freq, val});
            if (heap.size() > k) {
                heap.pop();
            }
        }
        while (!heap.empty()) {
            ans.push_back(heap.top().second);
            heap.pop();
        }
        return ans;
    }
};


