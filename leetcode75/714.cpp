#include <vector>
#include <algorithm>

using std::vector;
using std::max;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = static_cast<int>(prices.size());
        vector<vector<int>> dp(n, vector<int>(2));
        // dp[i][0] = max profit on day i, not holding
        // dp[i][1] = max profit on day i, holding
        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i] - fee); // not holding OR sell today
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]); // keep holding OR buy today
        }

        return dp[n-1][0];
    }
};

// follow-up: dp-0d, state machine

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = static_cast<int>(prices.size());
        int not_hold = 0;
        int holding = -prices[0];

        for (int i = 1; i < n; i++) {
            int new_not_hold = max(not_hold, holding + prices[i] - fee);
            int new_holding = max(holding, not_hold - prices[i]);
            not_hold = new_not_hold;
            holding = new_holding;
        }

        return not_hold;
    }
};
