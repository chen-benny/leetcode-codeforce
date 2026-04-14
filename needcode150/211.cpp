// trie with dfs for wildcard, T: O(m) insert, O(26^m) worst case with all ., S: O(mn)

#include <cstring>
#include <cstddef>
#include <string>

class WordDictionary {
private:
    struct Node {
        Node* children[26];
        bool isEnd;
        Node() : isEnd(false) { std::memset(children, 0, sizeof(children)); }
        ~Node() { for (int i = 0; i < 26; ++i) { delete children[i]; } }
    };

    static constexpr char BASE_CHAR = 'a';
    Node* root;

    bool dfs(Node* node, const std::string& word, int idx) {
        if (idx == static_cast<int>(word.size())) { return node->isEnd; }

        char c = word[idx];
        if (c == '.') {
            for (int i = 0; i < 26; ++i) {
                if (node->children[i] && dfs(node->children[i], word, idx + 1)) { return true; }
            }
            return false;
        }

        int ci = c - BASE_CHAR;
        if (!node->children[ci]) { return false; }
        return dfs(node->children[ci], word, idx + 1);
    }

public:
    WordDictionary() : root(new Node()) {}
    ~WordDictionary() { delete root; }

    void addWord(const std::string& word) {
        Node* curr = root;
        for (char c : word) {
            int idx = c - BASE_CHAR;
            if (!curr->children[idx]) { curr->children[idx] = new Node(); }
            curr = curr->children[idx];
        }
        curr->isEnd = true;
    }

    bool search(const std::string& word) {
        return dfs(root, word, 0);
    }
};

// wildcard worst case
// dfs early exit
// iterative wildcard
// cache behavior
// dfs over bfs for wildcard
// all '.'
