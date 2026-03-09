#include <vector>

using std::vector;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = static_cast<int>(temperatures.size());
        vector<int> res(n, 0);
        vector<int> stk; // indices of days haven't found a warmer day
        stk.reserve(n);

        for (int i = 0; i < n; i++) {
            while (!stk.empty() && temperatures[i] > temperatures[stk.back()]) {
                int prev = stk.back();
                stk.pop_back();
                res[prev] = i - prev;
            }

            stk.push_back(i);
        }

        return res;
    }
};
