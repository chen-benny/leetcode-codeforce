#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::max;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = static_cast<int>(text1.size());
        int n = static_cast<int>(text2.size());
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); // dp[i][j] = LCS len of text1[0..i-1] and text2[0..j-1]

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i-1] == text2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1; // match, ++count
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]); // skip char in text1 or text2
                }
            }
        }

        return dp[m][n];
    }
};

// follow-up: dp-1d compress

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = static_cast<int>(text1.size());
        int n = static_cast<int>(text2.size());
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= m; i++) {
            int diag = 0; // prev state: dp[i-1][j-1]
            for (int j = 1; j <= n; j++) {
                int above = dp[j]; // save state: dp[i-1][j]
                if (text1[i-1] == text2[j-1]) {
                    dp[j] = diag + 1;
                } else {
                    dp[j] = max(dp[j], dp[j-1]);
                }

                diag = above; // go right, above becomes diag
            }
        }

        return dp[n];
    }
};
