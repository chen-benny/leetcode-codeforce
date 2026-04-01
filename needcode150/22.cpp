// backtracking, T: O(4^n/√n) - Catalan number, S: O(n) - recursion path

#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> res;
        std::string cur;
        cur.reserve(2 * n);
        backtrack(res, cur, 0, 0, n);
        return res;
    }

private:
    void backtrack(std::vector<std::string>& res, std::string& cur,
                   int open, int close, int n) {
        if (static_cast<int>(cur.size()) == 2 * n) {
            res.push_back(cur);
            return;
        }
        
        if (open < n) {
            cur.push_back('(');
            backtrack(res, cur, open + 1, close, n);
            cur.pop_back();
        }
        if (close < open) {
            cur.push_back(')');
            backtrack(res, cur, open, close + 1, n);
            cur.pop_back();
        }
    }
};

/*
   - cur.reserve(2 * n)
   - Catalan number
   - backtracking vs DP
   ? why close < open
   ? gen in lexi order
*/
