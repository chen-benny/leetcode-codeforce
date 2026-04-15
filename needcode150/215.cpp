// min-heap of size k, T: O(nlogk), S: O(k)

#include <vector>
#include <queue>

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

        for (int x : nums) {
            minHeap.push(x);
            if (static_cast<int>(minHeap.size()) > k) { minHeap.pop(); }
        }
        return minHeap.top();
    }
};

// quick-select with 3-way partition, T: O(n) avg, S: O(1)

#include <vector>
#include <algorithm>
#include <random>
#include <utility>

class Solution{
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::mt19937 rng(std::random_device{}());
        std::shuffle(nums.begin(), nums.end(), rng);

        int target = static_cast<int>(nums.size()) - k;
        int lo = 0;
        int hi = static_cast<int>(nums.size()) - 1;

        while (lo < hi) {
            auto [lt, gt] = partition(nums, lo, hi);
            if (lt > target) { hi = lt - 1; }
            else if (gt < target) { lo = gt + 1; }
            else { break; }
        }
        return nums[target];
    }

private:
    std::pair<int, int> partition(std::vector<int>& nums, int lo, int hi) {
        int pivot = nums[lo];
        int lt = lo;
        int gt = hi;
        int i = lo;

        while (i <= gt) {
            if (nums[i] < pivot) { std::swap(nums[i++], nums[lt++]); }
            else if (nums[i] > pivot) { std::swap(nums[i], nums[gt--]); }
            else { ++i; }
        }
        return {lt, gt};
    }
};

// counting-sort with bound data, T: O(n + R), R = value range, S: O(R)

#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        constexpr int MIN_VAL = -10000;
        constexpr int MAX_VAL = 10000;
        constexpr int RANGE = MAX_VAL - MIN_VAL + 1;

        int count[RANGE];
        std::memset(count, 0, sizeof(count));

        for (int x : nums) { count[x - MIN_VAL]++; }
        
        for (int i = RANGE - 1; i >= 0; --i) {
            k -= count[i];
            if (k <= 0) { return i + MIN_VAL; }
        }
        return -1;
    }
};

// target = n - k
// heap vs quick-select
// 3-way partition necessity
// cache behavior
// streaming data
// counting-sort bound
