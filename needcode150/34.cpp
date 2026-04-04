// two binary-search, T: O(log(n)), S: O(1)

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        auto first = std::lower_bound(nums.begin(), nums.end(), target);
        if (first == nums.end() || *first != target) { return {-1, -1}; }

        auto last = std::upper_bound(nums.begin(), nums.end(), target);
        return {static_cast<int>(first - nums.begin()),
                static_cast<int>(last - nums.begin()) - 1};
    }
};

/*
   - lower_bound, upper_bound
   - first, early exit
   - cache behavior
   ? manually implement
   ? one binary search
*/
