// backtracking with duplicate skip, T: O(2^n), S: O(n) recursion path

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int>> res;
        std::vector<int> curr;
        backtrack(candidates, target, 0, curr, res);
        return res;
    }

private:
    void backtrack(std::vector<int>& candidates, int remain, int start,
                   std::vector<int>& curr, std::vector<std::vector<int>>& res) {
        if (remain == 0) {
            res.push_back(curr);
            return;
        }

        for (int i = start; i < static_cast<int>(candidates.size()); ++i) {
            if (candidates[i] > remain) { break; }
            if (i > start && candidates[i] == candidates[i - 1]) { continue; }

            curr.push_back(candidates[i]);
            backtrack(candidates, remain - candidates[i], i + 1, curr, res);
            curr.pop_back();
        }
    }
};

// i > start not i > 0 for duplicate skip
// i + 1 not i for no-reuse
// sort enables both optimization
// cache behavior
// why sort
