// sweep-line + max-heap, T: O(nlogn), S: O(n)

#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

class Solution {
public:
    std::vector<std::vector<int>> getSkyline(std::vector<std::vector<int>>& buildings) {
        // collect (x, idx) for both left and right edges
        std::vector<std::pair<int, int>> edges;
        edges.reserve(buildings.size() * 2);
        for (int i = 0; i < static_cast<int>(buildings.size()); ++i) {
            edges.push_back({buildings[i][0], i});
            edges.push_back({buildings[i][1], i});
        }
        std::sort(edges.begin(), edges.end());

        // {h, right_x} lazy del on right_x <= cur_x
        std::priority_queue<std::pair<int, int>> live;
        std::vector<std::vector<int>> res;
        int idx = 0;

        while (idx < static_cast<int>(edges.size())) {
            int currX = edges[idx].first;

            while (idx < static_cast<int>(edges.size()) && edges[idx].first == currX) {
                int b = edges[idx].second;
                if (buildings[b][0] == currX) {
                    live.push({buildings[b][2], buildings[b][1]});
                }
                ++idx;
            }

            while (!live.empty() && live.top().second <= currX) { live.pop(); }

            int curMax = live.empty() ? 0 : live.top().first;
            if (res.empty() || res.back()[1] != curMax) {
                res.push_back({currX, curMax});
            }
        }
        return res;
    }
};

// multi-set, T: O(nlogn), S: O(n)

#include <vector>
#include <set>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> getSkyline(std::vector<std::vector<int>>& buildings) {
        std::vector<std::pair<int, int>> events;
        events.reserve(buildings.size() * 2);
        for (auto& b : buildings) {
            events.push_back({b[0], -b[2]}); // start, neg-h
            events.push_back({b[1], b[2]}); // end, pos-h
        }
        std::sort(events.begin(), events.end());

        std::multiset<int> active;
        active.insert(0); // ground sentinel
        std::vector<std::vector<int>> res;
        int prevMax = 0;

        for (auto& [x, h] : events) {
            if (h < 0) { active.insert(-h); }
            else { active.erase(active.find(h)); }

            int curMax = *active.rbegin();
            if (curMax != prevMax) {
                res.push_back({x, curMax});
                prevMax = curMax;
            }
        }
        return res;
    }
};

// cache behavior
// std::multiset vs absl:btree_multiset
// negative height encoding
// *active.rbegin()
// multiset vs heap
// active.erase(active.find(h)) over active.erase(h)
