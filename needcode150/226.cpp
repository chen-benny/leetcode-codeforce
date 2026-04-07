// recursive, T: O(n), S: O(h) stack frames, h = tree height

#include <cstddef>

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) { return nullptr; }
        std::swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

// iterative bfs, T: O(n), S: O(w), w: max width

#include <queue>
#include <cstddef>
#include <algorithm>

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) { return nullptr; }
        std::queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            std::swap(node->left, node->right);
            if (node->left) { q.push(node->left); }
            if (node->right) { q.push(node->right); }
        }
        return root;
    }
};

/*
   - recursive vs iterative
   - std::swap
   _ std::queue overhead
   - cache hahavior
   ? prefer which
*/
