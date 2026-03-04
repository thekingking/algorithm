#include <vector>
#include <string>
#include <climits>
#include <stack>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return quick_select(nums, 0, n - 1, n - k);
    }

    int quick_select(vector<int>& nums, int l, int r, int k) {
        if (l == r) {
            return nums[k];
        }
        int pivot = nums[l], i = l - 1, j = r + 1;
        while (i < j) {
            do i++; while (nums[i] < pivot); // 遇到 >= pivot 的就停
            do j--; while (nums[j] > pivot); // 遇到 <= pivot 的就停
            if (i < j) swap(nums[i], nums[j]);
        }
        if (k <= j) return quick_select(nums, l, j, k);
        return quick_select(nums, j + 1, r, k);
    }
};