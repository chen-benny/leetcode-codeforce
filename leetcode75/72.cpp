#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::min;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = static_cast<int>(word1.size());
        int n = static_cast<int>(word2.size());
        // dp[i][j] = edit distance of word1[0..i) and word2[0..j)
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (int i = 0; i <= m; i++) { dp[i][0] = i; }
        for (int j = 0; j <= n; j++) { dp[0][j] = j; }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = 1 + min({dp[i-1][j-1], // replace char of word1[i]
                                        dp[i-1][j], // delete char of word1[i]
                                        dp[i][j-1]}); // insert char at word1[i] with word1[j]
                }
            }
        }

        return dp[m][n];
    }
};

// follow-up: dp-1d, compress

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = static_cast<int>(word1.size());
        int n = static_cast<int>(word2.size());
        vector<int> dp(n + 1); // dp[j] = edit dist of curr word1[0..i) with word2[0..j)
        for (int j = 0; j <= n; j++) { dp[j] = j; }

        for (int i = 1; i <= m; i++) {
            int diag = dp[0]; // dp[i-1][j-1]
            dp[0] = i; // dp[i][0] = i delete
            for (int j = 1; j <= n; j++) {
                int above = dp[j]; // save dp[i-1][j]
                if (word1[i-1] == word2[j-1]) {
                    dp[j] = diag;
                } else {
                    dp[j] = 1 + min({diag,
                                     above,
                                     dp[j-1]});
                }
                diag = above;
            }
        }

        return dp[n];
    }
};
