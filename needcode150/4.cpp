// binary-search on partition, T: O(log(min(m, n))), S: O(1)

#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        if (nums1.size() > nums2.size()) { // ensure binary-search on smaller array
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = static_cast<int>(nums1.size());
        int n = static_cast<int>(nums2.size());
        int lo = 0;
        int hi = m;

        while (lo <= hi) {
            int cut1 = lo + (hi - lo) / 2; // partition in nums1
            int cut2 = (m + n + 1) / 2 - cut1; // partition in nums2

            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int r1 = (cut1 == m) ? INT_MAX : nums1[cut1];
            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int r2 = (cut2 == n) ? INT_MAX : nums2[cut2];

            if (l1 <= r2 && l2 <= r1) { // correct partition
                if ((m + n) % 2 ==1) { return std::max(l1, l2); }
                else { return (std::max(l1, l2) + std::min(r1, r2)) / 2.0; }
            } else if (l1 > r2) {
                hi = cut1 - 1;
            } else {
                lo = cut1 + 1;
            }
        }
        return 0.0;
    }
};

// merge, T: O(m + n), S: O(1)

#include <vector>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        int m = static_cast<int>(nums1.size());
        int n = static_cast<int>(nums2.size());
        int total = m + n;
        int mid = total / 2;

        int i = 0;
        int j = 0;
        int prev = 0;
        int curr = 0;

        for (int k = 0; k <= mid; ++k) {
            prev = curr;
            if (i < m && (j >= n || nums1[i] <= nums2[j])) { curr = nums1[i++]; }
            else { curr = nums2[j++]; }
        }

        return (total % 2 == 1) ? curr : (prev + curr) / 2.0;
    }
};

/*
   - binary-search on smaller array
   - INT_MIN/INT_MAX sentinels
   - (m + n + 1) / 2
   - branch prediction
   - track prev and curr
   ? overflow on max(l1, l2) + min(r1, r1)
*/
