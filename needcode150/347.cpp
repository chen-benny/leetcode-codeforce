#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility>

using std::vector;
using std::unordered_map;
using std::sort;
using std::pair;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = static_cast<int>(nums.size());
        unordered_map<int, int> freq;
        freq.reserve(n);
        for (int val : nums) { ++freq[val]; }

        vector<pair<int, int>> entries(freq.begin(), freq.end());
        sort(entries.begin(), entries.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        });

        vector<int> res;
        res.reserve(k);
        for (int i = 0; i < k; i++) { res.push_back(entries[i].first); }
        return res;
    }
};

// follow-up: heap

#include <functional>

using std::push_heap;
using std::pop_heap;
using std::greater;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = static_cast<int>(nums.size());
        unordered_map<int, int> freq;
        freq.reserve(n);
        for (int val : nums) { ++freq[val]; }

        vector<pair<int, int>> heap; // (freq, val)
        heap.reserve(k + 1);
        for (const auto& [val, cnt] : freq) {
            heap.emplace_back(cnt, val);
            push_heap(heap.begin(), heap.end(), greater<pair<int, int>>{});
            if (static_cast<int>(heap.size()) > k) {
                pop_heap(heap.begin(), heap.end(), greater<pair<int, int>>{});
                heap.pop_back();
            }
        }

        vector<int> res;
        res.reserve(k);
        for (const auto& [cnt, val] : heap) { res.push_back(val); }
        return res;
    }
};

// follow-up: bucket sort

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = static_cast<int>(nums.size());
        unordered_map<int, int> freq;
        freq.reserve(n);
        for (int val : nums) { ++freq[val]; }

        vector<vector<int>> buckets(n + 1);
        for (const auto& [val, cnt] : freq) { buckets[cnt].push_back(val); }

        vector<int> res;
        res.reserve(k);
        for (int i = n; i >= 0 && static_cast<int>(res.size()) < k; i--) {
            for (int val : buckets[i]) {
                res.push_back(val);
                if (static_cast<int>(res.size()) == k) { break; }
            }
        }
        return res;
    }
};
