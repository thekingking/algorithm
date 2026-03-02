#include <vector>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l = nums1.size() + nums2.size();
        if (l % 2 == 1) {
            return getKthElement(nums1, nums2, (l + 1) / 2);
        }
        return (getKthElement(nums1, nums2, l / 2) + getKthElement(nums1, nums2, l / 2 + 1)) / 2;
    }

    double getKthElement(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        int i = 0, j = 0;
        while(true) {
            if (i == m) {
                return nums2[j + k - 1];
            }
            if (j == n) {
                return nums1[i + k - 1];
            }
            if (k == 1) {
                return min(nums1[i], nums2[j]);
            }
            int ni = min(i + k / 2 - 1, m - 1);
            int nj = min(j + k / 2 - 1, n - 1);
            if (nums1[ni] <= nums2[nj]) {
                k -= ni - i + 1;
                i = ni + 1;
            } else {
                k -= nj - j + 1;
                j = nj + 1;
            }
        }
    }
};