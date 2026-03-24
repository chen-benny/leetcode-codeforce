// hash-map + min-heap, keep size-k min-heap + evict least frequent, T: O(nlogk), S: O(n)

#include <vector>
#include <unordered_map>
#include <queue>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> freq;
        freq.reserve(nums.size());
        freq.max_load_factor(0.25f);
        for (int val : nums) { freq[val]++; };

        std::priority_queue<
            std::pair<int, int>,
            std::vector<std::pair<int, int>>,
            std::greater<>
        >minHeap;

        for (auto& [val, cnt] : freq) {
            minHeap.push({cnt, val});
            if (static_cast<int>(minHeap.size()) > k) { minHeap.pop(); }
        }

        std::vector<int> res;
        res.reserve(k);
        while (!minHeap.empty()) {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return res;
    }
};

// bucket-sort, freq is bounded by [1, n], idx as freq buckets, T: O(n), S: O(n)

#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        int n = static_cast<int>(nums.size());
        std::unordered_map<int, int> freq; // {val: cnt}
        freq.reserve(nums.size());
        freq.max_load_factor(0.25f);
        for (int val : nums) { freq[val]++; }

        // bucket[i] = list of val with cnt of i
        std::vector<std::vector<int>> bucket(n + 1);
        for (auto& [val, cnt] : freq) { bucket[cnt].push_back(val); }

        std::vector<int> res;
        res.reserve(k);
        for (int i = n ; i >= 1 && static_cast<int>(res.size()) < k; i--) {
            for (int val : bucket[i]) {
                res.push_back(val);
            }
        }
        return res;
    }
};

/*
   - cache behavior
   - heap vs bucket

   ? without hashmap
   ? k = 1
*/
