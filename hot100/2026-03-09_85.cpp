#include <vector>
#include <string>
#include <climits>
#include <stack>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> arr(amount + 1, amount + 1);
        arr[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (const int &c : coins) {
                if (c > i || arr[i - c] == amount + 1) {
                    continue;
                }
                arr[i] = min(arr[i], arr[i - c] + 1);
            }
        }
        return arr[amount] == amount + 1 ? -1 : arr[amount];
    }
};