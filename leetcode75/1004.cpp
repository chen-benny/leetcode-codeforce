class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        /*
         * Return the max num of consecutive 1's in binary nums[], with flip of at most k 0's
         *
         * Sliding-window and keep zeros, shrink if zeros exceed k
         * T: O(n), S: O(1)
         */
        int left = 0;
        int zeros = 0;
        int maxLen = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) {
                ++zeros;
            }

            while (zeros > k) {
                if (nums[left] == 0) {
                    --zeros;
                }
                ++left;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

// follow-up: never-shrink pattern
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        /* 
         * shrink for maintaining the min valid window
         * right steps 1, left steps 1 only when zeros > k -> trace the max valid window
         */
        int left = 0;
        int zeros = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) {
                ++zeros;
            }

            if (zeros > k) {
                if (nums[left] == 0) {
                    --zeros;
                }
                ++left;
            }
        }

        return nums.size() - left;
    }
};
