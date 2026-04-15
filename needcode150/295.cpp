// two heaps, T: O(logn) add, O(1) findMedian, S: O(n)

#include <queue>
#include <vector>

class MedianFinder {
private:
    std::priority_queue<int> maxHeap; // lower half, top is max of lower
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap; // upper half, top is min of upper

public:
    MedianFinder() = default;

    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (maxHeap.size() > minHeap.size()) { return maxHeap.top(); }
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};

// two-step insert invariant
// size invariant
// cache behavior
// stream nearly sorted
// O(1) insert?
// reservoir sampling?
