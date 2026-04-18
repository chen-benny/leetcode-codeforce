// backtracking with bitmask constraints, T: O(9^m) - m = empty cells, S: O(1)

#include <vector>
#include <cstring>

class Solution {
private:
    int rows[9], cols[9], boxes[9]; // bitmasks of used digits

    int boxIdx(int r, int c) { return (r / 3) * 3 + (c / 3); }

    bool solve(std::vector<std::vector<char>>& board) {
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] != '.') { continue; }

                int avail = (~(rows[r] | cols[c] | boxes[boxIdx(r, c)])) & 0x1FF;
                while (avail) {
                    int bit = avail & (-avail); // lowest set bit
                    int digit = __builtin_ctz(bit); // 0-indexed

                    rows[r] |= bit;
                    cols[c] |= bit;
                    boxes[boxIdx(r, c)] |= bit;
                    board[r][c] = '1' + digit;

                    if (solve(board)) { return true; }

                    rows[r] &= ~bit;
                    cols[c] &= ~bit;
                    boxes[boxIdx(r, c)] &= ~bit;
                    board[r][c] = '.';

                    avail &= avail - 1; // clear lowest set bit;
                }
                return false; // no valid digit - backtrack
            }
        }
        return true; // all cells filled
    }

public:
    void solveSudoku(std::vector<std::vector<char>>& board) {
        std::memset(rows, 0, sizeof(rows));
        std::memset(cols, 0, sizeof(cols));
        std::memset(boxes, 0, sizeof(boxes));

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') { continue; }
                int bit = 1 << (board[r][c] - '1');
                rows[r] |= bit;
                cols[c] |= bit;
                boxes[boxIdx(r, c)] |= bit;
            }
        }
        solve(board);
    }
};

// bool-array, T: O(9^m), S: O(1)

#include <vector>
#include <string>

class Solution {
public:
    void solveSudoku(std::vector<std::vector<char>>& board) {
        std::vector<bool> rows[9], cols[9], boxes[9];
        for (int i = 0; i < 9; ++i) {
            rows[i].assign(9, false);
            cols[i].assign(9, false);
            boxes[i].assign(9, false);
        }

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') { continue; }
                int d = board[r][c] - '1';
                rows[r][d] = cols[c][d] = boxes[boxIdx(r, c)][d] = true;
            }
        }
        solve(board, rows, cols, boxes, 0, 0);
    }

private:
    int boxIdx(int r, int c) { return (r / 3) * 3 + (c / 3); }

    bool solve(std::vector<std::vector<char>>& board,
               std::vector<bool> rows[], std::vector<bool> cols[], std::vector<bool> boxes[],
               int r, int c) {
        if (r == 9) { return true; }
        int nr = (c == 8) ? r + 1 : r;
        int nc = (c == 8) ? 0 : c + 1;

        if (board[r][c] != '.') { return solve(board, rows, cols, boxes, nr, nc); }

        for (int d = 0; d < 9; ++d) {
            if (rows[r][d] || cols[c][d] || boxes[boxIdx(r, c)][d]) { continue; }
            rows[r][d] = cols[c][d] = boxes[boxIdx(r, c)][d] = true;
            board[r][c] = '1' + d;
            if (solve(board, rows, cols, boxes, nr, nc)) { return true; }
            rows[r][d] = cols[c][d] = boxes[boxIdx(r, c)][d] = false;
            board[r][c] = '.';
        }
        return false;
    }
};


// bitmask constraint propagation
// avail & (~avail)
// avail &= avail - 1
// 0x1FF mask 9-bit mask
// cache behavior
// iter top-left to bottom-right
// __builtin_ctz portability
