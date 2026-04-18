// backtracking with bitmask constraints, T: O(n!), S: O(n)

#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> res;
        std::vector<int> queens(n, -1); // queens[r] = col of queen in row r
        solve(0, n, 0, 0, 0, queens, res);
        return res;
    }

private:
    void solve(int row, int n, int cols, int diag1, int diag2,
               std::vector<int>& queens, std::vector<std::vector<std::string>>& res) {
        if (row == n) {
            res.push_back(build(queens, n));
            return;
        }

        int avail = (~(cols | diag1 | diag2)) & ((1 << n) -1);
        while (avail) {
            int bit = avail & (-avail);
            int c = __builtin_ctz(bit);
            queens[row] = c;
            solve(row + 1, n, cols | bit,
                  (diag1 | bit) << 1, (diag2 | bit) >> 1,
                  queens, res);
            queens[row] = -1;
            avail &= avail - 1;
        }
    }

    std::vector<std::string> build(std::vector<int>& queens, int n) {
        std::vector<std::string> board(n, std::string(n, '.'));
        for (int r = 0; r < n; ++r) {
            board[r][queens[r]] = 'Q';
        }
        return board;
    }
};

// bool-array + matrix-encoding, T: O(n!), S: O(n)

#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> res;
        std::vector<int> queens(n, -1); // queens[r] = col of queen in row r
        std::vector<bool> cols(n, false), diag1(2 * n - 1, false), diag2(2 * n - 1, false);
        backtrack(0, n, queens, cols, diag1, diag2, res);
        return res;
    }

private:
    void backtrack(int row, int n, std::vector<int>& queens,
                   std::vector<bool>& cols, std::vector<bool>& diag1, std::vector<bool>& diag2,
                   std::vector<std::vector<std::string>>& res) {
        if (row == n ) {
            res.push_back(build(queens, n));
            return;
        }

        for (int c = 0; c < n; ++c) {
            int d1 = row - c + n - 1;
            int d2 = row + c;
            if (cols[c] || diag1[d1] || diag2[d2]) { continue; }

            queens[row] = c;
            cols[c] = diag1[d1] = diag2[d2] = true;
            backtrack(row + 1, n, queens, cols, diag1, diag2, res);
            cols[c] = diag1[d1] = diag2[d2] = false;
            queens[row] = -1;
        }
    }

    std::vector<std::string> build(std::vector<int>& queens, int n) {
        std::vector<std::string> board(n, std::string(n, '.'));
        for (int r = 0; r < n; ++r) { board[r][queens[r]] = 'Q'; }
        return board;
    }
};

// three bitmasks
// diagonal shift correctness
// (1 << n) -1 mask
// cache behavior
