#include <vector>
#include <limits>

using std::vector;

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (!root) { return 0; }

        int max_sum = std::numeric_limits<int>::min();
        int best_lv = 1;
        int curr_lv_idx = 1;

        // double buffer vectors for cache-friendly level-order traversal
        vector<const TreeNode*> curr_lv;
        vector<const TreeNode*> next_lv;
        curr_lv.reserve(5000);
        next_lv.reserve(5000);
        curr_lv.push_back(root);

        while (!curr_lv.empty()) {
            int curr_sum = 0;

            for (const TreeNode* node : curr_lv) {
                curr_sum += node->val;

                if (node->left) { next_lv.push_back(node->left); }
                if (node->right) { next_lv.push_back(node->right); }
            }

            if (curr_sum > max_sum) {
                max_sum = curr_sum;
                best_lv = curr_lv_idx;
            }

            curr_lv.swap(next_lv);
            next_lv.clear();
            ++curr_lv_idx;
        }

        return best_lv;
    }
};

// follow-up: dfs

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        vector<int> level_sums;

        level_sums.reserve(10000);

        dfs(root, 0, level_sums);

        int max_sum = level_sums[0];
        int best_lv = 1;

        for (int i = 1; i < level_sums.size(); i++) {
            if (level_sums[i] > max_sum) {
                max_sum = level_sums[i];
                best_lv = i + 1; // 0-indexed to 1-indexed level
            }
        }

        return best_lv;
    }

private:
    void dfs(const TreeNode* node, int depth, vector<int>& level_sums) {
        if (!node) { return; }

        if (depth == level_sums.size()) { // allocate the bucket when 1st time visit depth
            level_sums.push_back(node->val);
        } else {
            level_sums[depth] += node->val;
        }

        dfs(node->left, depth + 1, level_sums);
        dfs(node->right, depth + 1, level_sums);
    }
};
