#include <climits>

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        /*
         * Return true if nums has triplets (i < j < k) satisfying nums[i] < nums[j] < nums[k])
         *
         * Linear scan and maintain two vals, ensure val1 < val2, true case: (val1, val2, cur)
         * For case (old_val1, val2, new_val1, cur) still valid
         * T: O(n)
         * S: O(1)
         */
        int n = nums.size();
        int val1 = INT_MAX;
        int val2 = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (nums[i] <= val1) {
                val1 = nums[i];
            } else if (nums[i] <= val2) {
                val2 = nums[i];
            } else {
                return true;
            }
        }
        return false;
    }
};
