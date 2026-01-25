class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        /*
         * Return the pivot index of nums[]
         * pivot index: sum of left num == sum of right num of index
         * 
         * prefix-sum: linear traverse + pre-sum to get sum of left num
         * sum of right sum == total sum - sum of left num - nums[i]
         * T: O(n), S: O(1)
         */
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        int leftSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (leftSum == totalSum - leftSum - nums[i]) {
                return i;
            }
            leftSum += nums[i];
        }

        return -1;
    }
};
