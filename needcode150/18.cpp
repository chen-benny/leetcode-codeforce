// sort + two-pointers, fix i and j, two-pointer on [j+1, n-1], skip dups at four levels, T: O(n3), S: O(1)

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int n = static_cast<int>(nums.size());
        std::vector<std::vector<int>> tuple;

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) { continue; } // skip dup i

            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) { continue; }

                int lo = j + 1;
                int hi = n - 1;
                while (lo < hi) {
                    long long sum = static_cast<long long>(nums[i]) + nums[j] + nums[lo] + nums[hi];
                    if (sum == target) {
                        tuple.push_back({nums[i], nums[j], nums[lo], nums[hi]});
                        while (lo < hi && nums[lo] == nums[lo + 1]) { ++lo; }
                        while (lo < hi && nums[hi] == nums[hi - 1]) { --hi; }
                        ++lo;
                        --hi;
                    } else if (sum < target) {
                        ++lo;
                    } else {
                        --hi;
                    }
                }
            }
        }
        return tuple;
    }
};

/*
   - long long sum
   ? why j > i + 1
   ? bettern than O(n3)
   ? genralized kSum
*/
