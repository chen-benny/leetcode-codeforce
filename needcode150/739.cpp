// monotonic-stack, T: O(n), S: O(n)

#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        int n = static_cast<int>(temperatures.size());
        std::vector<int> res(n, 0);
        std::stack<int> stk; // indices of mono-descreasing temperatures

        for (int i = 0; i < n; i++) {
            while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
                int idx = stk.top();
                stk.pop();
                res[idx] = i - idx;
            }
            stk.push(i);
        }
        return res;
    }
};

/*
   - store indices
   - flat-stack-array
   - amortized O(1)
   - remaining stack entries
   ? equal temps
   ? strictly increasing temps
   ? real-world analogy
*/
