// trie with flat child array, T: O(m) insert/search/prefix - m: word length, S: O(mn) - total nodes

#include <cstring>
#include <string>
#include <cstddef>

class Trie {
private:
    struct Node {
        Node* children[26];
        bool isEnd;
        Node() : isEnd(false) { std::memset(children, 0, sizeof(children)); }
        ~Node() { for (int i = 0; i < 26; ++i) { delete children[i]; } }
    };

    static constexpr char BASE_CHAR = 'a';
    Node* root;

public:
    Trie() : root(new Node()){}
    ~Trie() { delete root; }
    
    void insert(const std::string& word) {
        Node* curr = root;
        for (char c : word) {
            int idx = c - BASE_CHAR;
            if (!curr->children[idx]) { curr->children[idx] = new Node(); }
            curr = curr->children[idx];
        }
        curr->isEnd = true;
    }

    bool search(const std::string& word) {
        Node* curr = root;
        for (char c : word) {
            int idx = c - BASE_CHAR;
            if (!curr->children[idx]) { return false; }
            curr = curr->children[idx];
        }
        return curr->isEnd;
    }

    bool startsWith(const std::string& prefix) {
        Node* curr = root;
        for (char c : prefix) {
            int idx = c - BASE_CHAR;
            if (!curr->children[idx]) { return false; }
            curr = curr->children[idx];
        }
        return true;
    }
};

// children[26] vs hash-map
// memset
// new Node() per node
// cache behavior
// destructor
// isEnd over count
// memory usage per node
