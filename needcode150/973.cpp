// max heap of size k, T: O(nlogk), S: O(k)

#include <vector>
#include <queue>

class Solution {
public:
    std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k) {
        auto cmp = [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[0]*a[0] + a[1]*a[1] < b[0]*b[0] + b[1]*b[1];
        };

        std::priority_queue<std::vector<int>,
                            std::vector<std::vector<int>>,
                            decltype(cmp)> maxHeap(cmp);

        for (auto& p : points) {
            maxHeap.push(p);
            if (static_cast<int>(maxHeap.size()) > k) { maxHeap.pop(); }
        }

        std::vector<std::vector<int>> res;
        res.reserve(k);
        while (!maxHeap.empty()) {
            res.push_back(maxHeap.top());
            maxHeap.pop();
        }
        return res;
    }
};

// quick-select, T: O(n), S: O(1)

#include <vector>
#include <algorithm>
#include <random>
#include <utility>

class Solution {
public:
    std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k) {
        std::mt19937 rng(std::random_device{}());
        std::shuffle(points.begin(), points.end(), rng);

        int lo = 0;
        int hi = static_cast<int>(points.size()) - 1;
        while (lo < hi) {
            auto [lt, gt] = partition(points, lo, hi);
            if (lt > k - 1) { hi = lt - 1; }
            else if (gt < k - 1) { lo = gt + 1; }
            else break;
        }
        return std::vector<std::vector<int>>(points.begin(), points.begin() + k);
    }

private:
    int dist(const std::vector<int>& p) { return p[0]*p[0] + p[1]*p[1]; }

    std::pair<int, int> partition(std::vector<std::vector<int>>& points, int lo, int hi) {
        int pivotDist = dist(points[lo]);
        int lt = lo;
        int gt = hi;
        int i = lo;
        while (i <= gt) {
            int d = dist(points[i]);
            if (d < pivotDist) { std::swap(points[i++], points[lt++]); }
            else if (d > pivotDist) { std::swap(points[i], points[gt--]); }
            else { ++i; }
        }
        return {lt, gt};
    }
};

// square distance over sqrt
// heap vs quickselect
// max-heap for closest, min-heap for largest
// cache behavior
// quickselect 3-way
