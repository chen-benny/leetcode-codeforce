// last + right prefix-arrays, T: O(n), S: O(n)

#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        std::vector<int> left(n), right(n), res(n);

        left[0] = 1;
        for (int i = 1; i < n; i++) { left[i] = left[i - 1] * nums[i - 1]; }

        right[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) { right[i] = right[i + 1] * nums[i + 1]; }

        for (int i = 0; i < n; i++) { res[i] = left[i] * right[i]; }

        return res;
    }
};


// in-place right-pass, res as left prefix-array, T: O(n), S: O(1)

#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        std::vector<int> res(n);

        res[0] = 1;
        for (int i = 1; i < n; i++) { res[i] = res[i - 1] * nums[i - 1]; }

        int right = 1;
        for (int i = n - 1; i >= 0; i--) {
            res[i] *= right;
            right *= nums[i];
        }

        return res;
    }
};

/*
   - cache behavior
   - branch prediction

   ? handle zeros in array
   ? solve with division
*/
