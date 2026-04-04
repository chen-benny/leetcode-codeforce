// binary-search on answer, T: O(n * log(sum - max)), S: O(1)

#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int splitArray(std::vector<int>& nums, int k) {
        long long lo = *std::max_element(nums.begin(), nums.end());
        long long hi = std::accumulate(nums.begin(), nums.end(), 0LL);

        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (canSplit(nums, k, mid)) { hi = mid; }
            else { lo = mid + 1; }
        }
        return static_cast<int>(lo);
    }

private:
    bool canSplit(std::vector<int>& nums, int k, long long limit) {
        int parts = 1;
        long long sum = 0;
        for (int x : nums) {
            if (sum + x > limit) {
                ++parts;
                sum = x;
            } else {
                sum += x;
            }
        }
        return parts <= k;
    }
};

/*
   - long long
   - monotone property
   - lower_bound
   - cache behavior
   ? std::accumulate with 0LL
   ? dp solution?
*/
