#include <vector>
#include <algorithm>
#include <functional>

using std::vector;
using std::push_heap;
using std::pop_heap;
using std::greater;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = static_cast<int>(costs.size());
        vector<int> left;
        vector<int> right;
        left.reserve(candidates + k);
        right.reserve(candidates + k);

        int lo = 0; // point to next left
        int hi = n - 1; // point to next right

        for (int i = 0; i < candidates && lo <= hi; i++) {
            left.push_back(costs[lo++]);
            push_heap(left.begin(), left.end(), greater<int>{});
        }
        for (int i = 0; i < candidates && lo <= hi; i++) {
            right.push_back(costs[hi--]);
            push_heap(right.begin(), right.end(), greater<int>{});
        }

        long long total = 0;
        for (int i = 0; i < k; i++) {
            if (right.empty() || (!left.empty() && left.front() <= right.front())) {
                total += left.front();
                pop_heap(left.begin(), left.end(), greater<int>{});
                left.pop_back();
                if (lo <= hi) {
                    left.push_back(costs[lo++]);
                    push_heap(left.begin(), left.end(), greater<int>{});
                }
            } else {
                total += right.front();
                pop_heap(right.begin(), right.end(), greater<int>{});
                right.pop_back();
                if (lo <= hi) {
                    right.push_back(costs[hi--]);
                    push_heap(right.begin(), right.end(), greater<int>{});
                }
            }
        }

        return total;
    }
};
