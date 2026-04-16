// backtracking, T: O(nm4^l), S: O(l) recursion path

#include <vector>
#include <string>

class Solution {
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        int m = static_cast<int>(board.size());
        int n = static_cast<int>(board[0].size());

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (dfs(board, word, r, c, 0)) { return true; }
            }
        }
        return false;
    }

private:
    bool dfs(std::vector<std::vector<char>>& board, const std::string word,
             int r, int c, int idx) {
        if (idx == static_cast<int>(word.size())) { return true; }

        int m = static_cast<int>(board.size());
        int n = static_cast<int>(board[0].size());

        if (r < 0 || r >= m || c < 0 || c >= n) { return false; }
        if (board[r][c] != word[idx]) { return false; }

        char tmp = board[r][c];
        board[r][c] = '#'; // mark visited

        constexpr int DR[] = {-1, 1, 0, 0};
        constexpr int DC[] = {0, 0, -1, 1};

        bool found = false;
        for (int d = 0; d < 4 && !found; ++d) {
            found = dfs(board, word, r + DR[d], c + DC[d], idx + 1);
        }

        board[r][c] = tmp; // restore
        return found;
    }
};

// optimized backtracking with frequency pruning + rare-end start

#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

class Solution {
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        int m = static_cast<int>(board.size());
        int n = static_cast<int>(board[0].size());
        int l = static_cast<int>(word.size());

        if (l > m * n) { return false; }

        constexpr int ALPHA_SIZE = 128;
        int boardFreq[ALPHA_SIZE];
        int wordFreq[ALPHA_SIZE];
        std::memset(boardFreq, 0, sizeof(boardFreq));
        std::memset(wordFreq, 0, sizeof(wordFreq));

        for (auto& row : board) {
            for (char c : row) { boardFreq[c]++; }
        }
        for (char c : word) { wordFreq[c]++; }
        for (int i = 0; i < ALPHA_SIZE; ++i) {
            if (wordFreq[i] > boardFreq[i]) { return false; }
        }

        if (boardFreq[static_cast<unsigned char>(word.front())] >
            boardFreq[static_cast<unsigned char>(word.back())]) {
            std::reverse(word.begin(), word.end());
        }

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (dfs(board, word, r, c, 0, m, n)) { return true; }
            }
        }
        return false;
    }

private:
    bool dfs(std::vector<std::vector<char>>& board, const std::string& word,
             int r, int c, int idx, int m, int n) {
        if (r < 0 || r >= m || c < 0 || c >= n) { return false; }
        if (board[r][c] != word[idx]) { return false; }
        if (idx == static_cast<int>(word.size()) - 1) { return true; }

        char tmp = board[r][c];
        board[r][c] = '#';
        bool found = dfs(board, word, r + 1, c, idx + 1, m, n) ||
                     dfs(board, word, r - 1, c, idx + 1, m, n) ||
                     dfs(board, word, r, c + 1, idx + 1, m, n) ||
                     dfs(board, word, r, c - 1, idx + 1, m, n);
        board[r][c] = tmp;
        return found;
    }
};

// frequency pruning
// rare-end heuristic
// in-place '#' marking
// short-circut || in dfs
// m, n passed as parameters
// cache behavior
