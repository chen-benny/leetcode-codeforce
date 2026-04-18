// backtracking + dp palindrome precompute, T: O(n2^n), S: O(n2)

#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::vector<std::string>> partition(std::string s) {
        int n = static_cast<int>(s.size());
        std::vector<std::vector<bool>> isPalin(n, std::vector<bool>(n, false));

        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (s[i] == s[j] && (j - i <= 2 || isPalin[i + 1][j - 1])) {
                    isPalin[i][j] = true; // dp[i][j] = true if s[i..j] is palindrome
                }
            }
        }

        std::vector<std::vector<std::string>> res;
        std::vector<std::string> curr;
        backtrack(s, 0, isPalin, curr, res);
        return res;
    }

private:
    void backtrack(const std::string& s, int start,
                   std::vector<std::vector<bool>>& isPalin,
                   std::vector<std::string>& curr,
                   std::vector<std::vector<std::string>>& res) {
        if (start == static_cast<int>(s.size())) {
            res.push_back(curr);
            return;
        }

        for (int end = start; end < static_cast<int>(s.size()); ++end) {
            if (!isPalin[start][end]) { continue; }
            curr.push_back(s.substr(start, end - start + 1));
            backtrack(s, end + 1, isPalin, curr, res);
            curr.pop_back();
        }
    }
};

// dp recurrence
// bottom-up direction
// O(1) palindrome check in backtracking
// s.substr allocation
// cache behavior
// precompute palindrome over checking on the fly
// avoid O(n2) dp table?
