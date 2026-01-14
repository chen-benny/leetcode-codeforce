#include <vector>

using std::vector;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*
         * Return an array where each element is product of all elements in nums except nums[i]
         *
         * Product Except itself == product of left * product or right
         * Each linear scan can trace product of one side && update one part in place
         * T: O(n)
         * S: O(1)
         */
        int n = nums.size();
        vector<int> res(n, 1);

        int pre = 1;
        for (int i = 0; i < n; i++) {
            res[i] = pre;
            pre *= nums[i];
        }

        int suff = 1;
        for (int i = n - 1; i >=0 ; i--) {
            res[i] *= suff;
            suff *= nums[i];
        }
        return res;
    }
};
