// backtracking, T: O(n2^n), S: O(n) recursion path

#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::vector<int> curr;
        backtrack(nums, 0, curr, res);
        return res;
    }

private:
    void backtrack(std::vector<int>& nums, int start, std::vector<int>& curr,
                   std::vector<std::vector<int>>& res) {
        res.push_back(curr);

        for (int i = start; i < static_cast<int>(nums.size()); ++i) {
            curr.push_back(nums[i]);
            backtrack(nums, i + 1, curr, res);
            curr.pop_back();
        }
    }
};

// bitmask, T: O(n2^n), S: O(1)

#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int total = 1 << n;
        std::vector<std::vector<int>> res;
        res.reserve(total);

        for (int mask = 0; mask < total; ++mask) {
            std::vector<int> curr;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) { curr.push_back(nums[i]); }
            }
            res.push_back(std::move(curr));
        }
        return res;
    }
};

// backtracking vs bitmask
// res.reserve(1 <, n)
// std::move(curr)
// bitmask cache behavior
// bitmask for n > 32
