// backtracking, T: O(n4^n), S: O(n) recursion path

#include <vector>
#include <string>
#include <cstring>

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        if (digits.empty()) { return {}; }
        std::vector<std::string> res;
        std::string curr;
        curr.reserve(digits.size());
        backtrack(digits, 0, curr, res);
        return res;
    }

private:
    static constexpr const char* MAP[] = {
        "", "", "abc", "def",
        "ghi", "jkl", "mno", "pqrs",
        "tuv", "wxyz"
    };

    void backtrack(const std::string& digits,
                   int idx, std::string& curr,
                   std::vector<std::string>& res) {
        if (idx == static_cast<int>(digits.size())) {
            res.push_back(curr);
            return;
        }
        for (const char* c = MAP[digits[idx] - '0']; *c; ++c) {
            curr.push_back(*c);
            backtrack(digits, idx + 1, curr, res);
            curr.pop_back();
        }
    }
};

// compiled-time string table
// curr.reserve(digits.size())
// pointer iteration vs index loop
// cache behavior
// O(n4^n) ?
// iterative bfs ?
