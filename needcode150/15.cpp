// sort + two-pointers, fix i, shrink window [i+1, n-1] with two pointers, skip dup, T: O(n2), S: O(1)

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int n = static_cast<int>(nums.size());
        std::vector<std::vector<int>> triplets;

        for (int i = 0; i < n - 2; i++) {
            if (nums[i] > 0) { break; } // sorted: no triplets sums to 0
            if (i > 0 && nums[i] == nums[i - 1]) { continue; } // skip dup i

            int lo = i + 1;
            int hi = n - 1;
            while (lo < hi) {
                int sum = nums[i] + nums[lo] + nums[hi];
                if (sum == 0) {
                    triplets.push_back({nums[i], nums[lo], nums[hi]});
                    while (lo < hi && nums[lo] == nums[lo + 1]) { ++lo; } // skip dup lo
                    while (lo < hi && nums[hi] == nums[hi - 1]) { --hi; } // skip dup lo
                    ++lo;
                    --hi;
                } else if (sum < 0) {
                    ++lo;
                } else {
                    --hi;
                }
            }
        }
        return triplets;
    }
};

/*
   - branch prediction
   ? why sort first
   ? dup skip
   ? better than O(n2)
   ? extend to 4sum
   ? all zeros array
*/
