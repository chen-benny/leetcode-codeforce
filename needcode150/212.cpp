// trie + backtracking, T: O(mn4^(mn)), S: O(total chars in words)

#include <vector>
#include <string>
#include <cstring>
#include <cstddef>

class Solution {
private:
    struct Node {
        Node* children[26];
        bool isEnd;
        int refs; // count of words passing through, prune dead branches
        Node() : isEnd(false), refs(0) { std::memset(children, 0, sizeof(children)); }
        ~Node() { for (int i = 0; i < 26; ++i) { delete children[i]; } }
    };

    static constexpr char BASE_CHAR = 'a';
    Node* root;

    void insert(const std::string& word) {
        Node* curr = root;
        for (char c : word) {
            int idx = c - BASE_CHAR;
            if (!curr->children[idx]) { curr->children[idx] = new Node(); }
            curr = curr->children[idx];
            curr->refs++;
        }
        curr->isEnd = true;
    }

    void dfs(std::vector<std::vector<char>>& board, int r, int c,
             Node* node, std::string& path, std::vector<std::string>& res) {
        int rows = static_cast<int>(board.size());
        int cols = static_cast<int>(board[0].size());

        if (r < 0 || r >= rows || c < 0 || c >= cols) { return; }

        char ch = board[r][c];
        if (ch == '#') { return; } // visited

        int idx = ch - BASE_CHAR;
        if (!node->children[idx] || node->children[idx]->refs == 0) { return; }

        node = node->children[idx];
        path.push_back(ch);
        board[r][c] = '#'; // mark visited

        if (node->isEnd) {
            res.push_back(path);
            node->isEnd = false; // de-dup
            node->refs--; // prune exhuasted branch
        }

        constexpr int DR[] = {-1, 1, 0, 0};
        constexpr int DC[] = {0, 0, -1, 1};
        for (int d = 0; d < 4; ++d) {
            dfs(board, r + DR[d], c + DC[d], node, path, res);
        }

        board[r][c] = ch; // restore
        path.pop_back();
    }

public:
    Solution() : root(new Node()) {}
    ~Solution() { delete root; }
    
    std::vector<std::string> findWords(std::vector<std::vector<char>>& board,
                                       std::vector<std::string>& words) {
        for (auto& w : words) { insert(w); }

        std::vector<std::string> res;
        std::string path;

        int rows = static_cast<int>(board.size());
        int cols = static_cast<int>(board[0].size());

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                dfs(board, r, c, root, path, res);
            }
        }
        return res;
    }
};

// refs counter
// node->isEnd = false de-dup
// mark visited on board[r][c]
// cache behavior
// trie over individual word dfs
// no match words on board
