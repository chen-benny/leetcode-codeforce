// dfs, T: O(mn), S: O(mn) recursion depth

#include <vector>

class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        int m = static_cast<int>(grid.size());
        int n = static_cast<int>(grid[0].size());
        int components = 0;

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == '1') {
                    dfs(grid, r, c, m, n);
                    ++components;
                }
            }
        }
        return components;
    }

private:
    void dfs(std::vector<std::vector<char>>& grid,
             int r, int c, int m, int n) {
        if (r < 0 || r >= m || c < 0 || c >= n) { return; }
        if (grid[r][c] != '1') { return; }
        
        grid[r][c] = '#'; // mark visited
        dfs(grid, r + 1, c, m, n);
        dfs(grid, r - 1, c, m, n);
        dfs(grid, r, c + 1, m, n);
        dfs(grid, r, c - 1, m, n);
    }
};

// union-find, T: O(mn*a(mn)), S: O(mn)

#include <vector>
#include <numeric>
#include <utility>

class Solution {
private:
        std::vector<int> root, rank_;
        int components;

        int find(int x) {
            if (root[x] != x) { root[x] = find(root[x]); }
            return root[x];
        }

        void unite(int a, int b) {
            a = find(a);
            b = find(b);
            if (a == b) { return; }

            if (rank_[a] < rank_[b]) { std::swap(a, b); }
            root[b] = a;
            if (rank_[a] == rank_[b]) { rank_[a]++; }
            --components;
        }

public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        int m = static_cast<int>(grid.size());
        int n = static_cast<int>(grid[0].size());
        int total = m * n;

        root.resize(total);
        rank_.resize(total, 0);
        std::iota(root.begin(), root.end(), 0);
        components = 0;

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == '1') {
                    ++components;
                    if (r + 1 < m && grid[r+1][c] == '1') { unite(r * n + c, (r + 1) * n + c); }
                    if (c + 1 < n && grid[r][c+1] == '1') { unite(r * n + c, r * n + c + 1); }
                }
            }
        }
        return components;
    }
};

// dfs in-place marking
// union-find only right and down
// dfs stack depth
// std::iota
// cache behavior
// dfs vs bfs vs uf ?
