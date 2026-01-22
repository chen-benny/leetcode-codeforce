class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        /*
         * Return the max avg of contiguous sub arr of k size in nums[], less than 10-5 error
         *
         * Sliding window exhuast all possible sub arr of k
         * T: O(n), S: O(1)
         */
        int winSum = 0;
        for (int i = 0; i < k; i++) {
            winSum += nums[i];
        }

        int maxSum = winSum;
        for (int i = k; i < nums.size(); i++) {
            // winSum += nums[i] - nums[i-k]; // sequentail dependency
            winSum += nums[i];
            winSum -= nums[i-k]; // parallel memory access optmization
            maxSum = max(maxSum, winSum);
        }

        return (double)maxSum / k;
    }
};
