class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        /*
         * Return max len of sub arr containing only 1's of binary nums[] after deleting one elem
         *
         * Never-thrink window: trace only maxLen, step left only when finding a zero
         * T: O(n), S: O(1)
         */
        int left = 0;
        int zeros = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) {
                ++zeros;
            }

            if (zeros > 1) { // allow one zero
                if (nums[left] == 0) {
                    --zeros;
                }
                ++left;
            }
        }

        return nums.size() - left - 1; // must delete one elem
    }
};

// traditional
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0;
        int zeros = 0;
        int maxLen = 0;

        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] == 0) ++zeros;

            // Shrink while more than 1 zero
            while (zeros > 1) {
                if (nums[left] == 0) --zeros;
                ++left;
            }

            // Length after deleting one element
            maxLen = max(maxLen, right - left);
        }

        return maxLen;
    }
};
