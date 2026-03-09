#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = static_cast<int>(points.size());
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int arrows = 1;
        int prev_end = points[0][1];

        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > prev_end) { // no-overlapping
                ++arrows;
                prev_end = points[i][1];
            }
        }

        return arrows;
    }
};
