// backtracking, T: O(2^(target/min)), S: O(target/min) recursion path

#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
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
        if (remain < 0) { return; }

        for (int i = start; i < static_cast<int>(candidates.size()); ++i) {
            curr.push_back(candidates[i]);
            backtrack(candidates, remain - candidates[i], i, curr, res);
            curr.pop_back();
        }
    }
};

// i not i+1 for reuse
// pruning with sort
// curr.reserve(target / min_candidates)
// cache behavior
// start index over a visited set
// candidates has duplicate
