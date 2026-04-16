// backtracking with duplicate skip, T: O(n2^n), S: O(n) recursion path

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res;
        std::vector<int> curr;
        backtrack(nums, 0, curr, res);
        return res;
    }

private:
    void backtrack(std::vector<int>& nums, int start,
                   std::vector<int>& curr, std::vector<std::vector<int>>& res) {
        res.push_back(curr);

        for (int i = start; i < static_cast<int>(nums.size()); ++i) {
            if (i > start && nums[i] == nums[i - 1]) { continue; }
            curr.push_back(nums[i]);
            backtrack(nums, i + 1, curr, res);
            curr.pop_back();
        }
    }
};

// duplicate skip
// record every node not just leaves
// std::move?
// cache behavior
