#include <vector>
#include <utility>

using std::vector;
using std::pair;
using std::swap;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = static_cast<int>(grid.size());
        int n = static_cast<int>(grid[0].size());
        constexpr int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        vector<pair<int, int>> curr_lv;
        vector<pair<int, int>> next_lv;
        curr_lv.reserve(m * n);
        next_lv.reserve(m * n);
        int fresh = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 2) {
                    curr_lv.emplace_back(r, c);
                } else if (grid[r][c] == 1) {
                    ++fresh;
                }
            }
        }

        int minutes = 0;
        while (!curr_lv.empty() && fresh > 0) {
            ++minutes;
            for (const auto& [r, c] : curr_lv) {
                for (const auto& [dr, dc] : dirs) {
                    int nr = r + dr;
                    int nc = c + dc;
                    
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) { continue; }

                    if (grid[nr][nc] != 1) { continue; }

                    grid[nr][nc] = 2;
                    --fresh;
                    next_lv.emplace_back(nr, nc);
                }
            }

            curr_lv.clear();
            swap(curr_lv, next_lv);
        }

        return fresh == 0 ? minutes : -1;
    }
};
