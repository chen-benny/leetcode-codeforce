#include <vector>
#include <utility>

using std::vector;
using std::pair;
using std::swap;

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = static_cast<int>(maze.size());
        int n = static_cast<int>(maze[0].size());
        constexpr int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        vector<pair<int, int>> curr_lv;
        vector<pair<int, int>> next_lv;
        curr_lv.reserve(m * n);
        next_lv.reserve(m * n);
        curr_lv.emplace_back(entrance[0], entrance[1]);
        maze[entrance[0]][entrance[1]] = '+'; // marked visited
        int steps = 0;

        while (!curr_lv.empty()) {
            ++steps;
            for (const auto& [r, c] : curr_lv) {
                for (const auto& [dr, dc] : dirs) {
                    int nr = r + dr;
                    int nc = c + dc;
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) { continue; }

                    if (maze[nr][nc] == '+') { continue; }

                    if (nr == 0 || nr == m - 1 || nc == 0 || nc == n - 1) { return steps; }
                    maze[nr][nc] = '+';
                    next_lv.emplace_back(nr, nc);
                }
            }

            curr_lv.clear();
            swap(curr_lv, next_lv);
        }

        return -1;
    }
};
