#include <vector>
#include <queue>
#include <functional>

using std::vector;
using std::priority_queue;
using std::greater;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int num : nums) {
            minHeap.push(num);

            if (static_cast<int>(minHeap.size()) > k) { minHeap.pop(); }
        }

        return minHeap.top();
    }
};

// follow-up: quick-select(3-way partition)

#include <cstdlib>
#include <utility>

using std::swap;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = static_cast<int>(nums.size());
        // vector<int> arr(nums.begin(), nums.end()); // copy nums if needed
        shuffle(nums);
        int target = n - k; // kth largest = (n-k)th smallest
        int lo = 0;
        int hi = n - 1;

        while (lo <= hi) {
            int pvt = partition(nums, lo, hi);
            if (pvt > target) {
                hi = pvt - 1;
            } else if (pvt < target) {
                lo = pvt + 1;
            } else {
                return nums[pvt];
            }
        }
        return -1;
    }


private:
    int partition(vector<int>& nums, int lo, int hi) {
        int pval = nums[lo];
        int lt = lo; // [lo..lt) < pval
        int gt = hi; // (gt..hi] > pval
        int i = lo; // [lo..gt] = pval

        while (i <= gt) {
            if (nums[i] > pval) {
                swap(nums[i], nums[gt--]);
            } else if (nums[i] < pval) {
                swap(nums[i++], nums[lt++]);
            } else {
                ++i;
            }
        }

        return lt + (gt - lt) / 2;
    }

    void shuffle(vector<int>& nums) {
        size_t n = nums.size();
        for (size_t i = 0; i < n; i++) {
            size_t r = i + rand() % (n - i);
            swap(nums[i], nums[r]);
        }
    }
};

// follow-up: STL, introselect(quickselect, fallback to median-of-medians)
#include <algorithm>

using std::nth_element;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.end() - k, nums.end());
        return nums[nums.size() - k];
    }
};
