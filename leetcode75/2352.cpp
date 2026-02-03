#include <vector>
#include <map>

using std::vector;
using std::map;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        map<vector<int>, int> count;

        for (int r = 0; r < n; r++) {
            ++count[grid[r]];
        }

        int cnt = 0;
        for (int c = 0; c < n; c++) {
            vector<int> tmp;
            for (int r = 0; r < n; r++) {
                tmp.push_back(grid[r][c]);
            }
            cnt += count[tmp];
        }
        return cnt;
    }
};
