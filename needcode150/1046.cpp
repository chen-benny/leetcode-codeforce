// max-heap, T: O(nlogn), S: O(n)

#include <vector>
#include <queue>

class Solution {
public:
    int lastStoneWeight(std::vector<int>& stones) {
        std::priority_queue<int> maxHeap(stones.begin(), stones.end());

        while (maxHeap.size() > 1) {
            int y = maxHeap.top(); maxHeap.pop();
            int x = maxHeap.top(); maxHeap.pop();
            if (x != y) { maxHeap.push(y - x); }
        }
        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};

// range constructor O(n) heapify
// if (x != y)
// early termination
// cache behavior
// max-heap over sort + two-pointers
