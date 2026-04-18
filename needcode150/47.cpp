// backtracking with visited array + duplicate skip, T: O(nn!), S: O(n) recursion path

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res;
        std::vector<int> curr;
        std::vector<bool> visited(nums.size(), false);
        curr.reserve(nums.size());
        backtrack(nums, visited, curr, res);
        return res;
    }

private:
    void backtrack(std::vector<int>& nums, std::vector<bool>& visited,
                   std::vector<int>& curr, std::vector<std::vector<int>>& res) {
        if (curr.size() == nums.size()) {
            res.push_back(curr);
            return;
        }

        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            if (visited[i]) { continue; }
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) { continue; }
            visited[i] = true;
            curr.push_back(nums[i]);
            backtrack(nums, visited, curr, res);
            curr.pop_back();
            visited[i] = false;
        }
    }
};

// !visited[i-1]
// visited array vs swap-based
// curr.reserve(nums.size())
// cache behavior
// sort first
