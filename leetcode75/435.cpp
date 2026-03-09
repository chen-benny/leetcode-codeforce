#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = static_cast<int>(intervals.size());
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int keep = 1;
        int prev_end = intervals[0][1];

        for (int i = 1; i < n; i++) {
            if (intervals[i][0] >= prev_end) {
                ++keep;
                prev_end = intervals[i][1];
            }
        }

        return n - keep;
    }
};
