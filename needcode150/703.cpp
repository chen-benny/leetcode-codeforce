// min-heap with size k, T: O(logk) per add, S: O(k)

#include <vector>
#include <queue>

class KthLargest {
private:
    int k;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

public:
    KthLargest(int k, std::vector<int>& nums) : k(k) {
        for (int x : nums) { add(x); }
    }

    int add(int val) {
        minHeap.push(val);
        if (static_cast<int>(minHeap.size()) > k) { minHeap.pop(); }
        return minHeap.top();
    }
};

// min heap
// heap size invariant
// add include init
// std::priority_queue overhead
// cache behavior
// k > n init
// O(1) add amortized?
