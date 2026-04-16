// backtracking with swap, T: O(nn!), S: O(n) recursion path

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        backtrack(nums, 0, res);
        return res;
    }

private:
    void backtrack(std::vector<int>& nums, int start,
                   std::vector<std::vector<int>>& res) {
        if (start == static_cast<int>(nums.size())) {
            res.push_back(nums);
            return;
        }

        for (int i = start; i < static_cast<int>(nums.size()); ++i) {
            std::swap(nums[start], nums[i]);
            backtrack(nums, start + 1, res);
            std::swap(nums[start], nums[i]);
        }
    }
};

// swap-based vs visited-array
// res.push_back(nums) at leaf
// swap correctness
// cache behavior
