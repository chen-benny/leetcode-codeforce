#include <vector>

using std::vector;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int r = 1; r < m; r++) {
            for (int c = 1; c < n; c++) {
                dp[r][c] = dp[r - 1][c] + dp[r][c - 1]; // dp[r - 1] is only accessed one time -> in-place update
            }
        }

        return dp[m - 1][n - 1];
    }
};


// follow-up: dp-1d compress

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        for (int r = 1; r < m; r++) {
            for (int c = 1; c < n; c++) {
                dp[c] += dp[c - 1]; // dp[c] = num of uniq paths from (0, 0) to (cur_r, c)
            }
        }
        
        return dp[n - 1];
    }
};

// follow-up: combinatorics

#include <algorithm>

using std::min;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int total = m - 1 + n - 1;
        int k = min(m - 1, n - 1);
        long long res = 1;

        for (int i = 0; i < k; i++) {
            res = res * (total - i) / (i + 1);
        }

        return static_cast<int>(res);
    }
};
