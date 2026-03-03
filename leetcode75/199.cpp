#include <vector>

using std::vector;

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> view;
        if (!root) { return view; }

        view.reserve(100);

        vector<const TreeNode*> curr_lv;
        vector<const TreeNode*> next_lv;
        curr_lv.reserve(50);
        next_lv.reserve(50);
        curr_lv.push_back(root);

        while (!curr_lv.empty()) {
            // level order traversal, last elem is rightmost
            view.push_back(curr_lv.back()->val);

            for (const TreeNode* node: curr_lv) {
                if (node->left) { next_lv.push_back(node->left); }
                if (node->right) { next_lv.push_back(node->right); }
            }

            curr_lv.swap(next_lv); // O(1) ptr swap
            next_lv.clear();
        }

        return view;
    }
};

// follow-up: dfs
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> view;

        view.reserve(100);

        dfs(root, 0, view);
        return view;
    }

private:
    void dfs(const TreeNode* node, int depth, vector<int>& view) {
        if (!node) { return; }

        // right-lean dfs, the first node in a depth is rightmost
        if (depth == view.size()) { view.push_back(node->val); }

        dfs(node->right, depth + 1, view);
        dfs(node->left, depth + 1, view);
    }
};
