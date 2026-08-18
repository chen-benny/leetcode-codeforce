#include <vector>
#include <algorithm> // std::max, std::sort

// sort + scan, T: O(nlogn), S: O(1)
class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        if (nums.empty()) { return 0; }
        std::sort(nums.begin(), nums.end());

        int maxLen = 1;
        int len = 1;
        for (int i = 1; i < static_cast<int>(nums.size()); i++) {
            if (nums[i] == nums[i - 1]) { continue; }
            cur = (nums[i] == nums[i - 1] + 1) ? cur + 1 : 1;
            maxLen = std::max(maxLen, len);
        }
        return maxLen;
    }
};

// hash-set, T: O(n) amortized, S: O(n)

#include <unordered_set>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_set<int> visited;
        visited.reserve(nums.size());
        visited.max_load_factor(0.25f);
        visited.insert(nums.begin(), nums.end());

        int maxLen = 0;
        for (int v : visited) {
            if (visited.count(v - 1)) { continue; } // not a start

            int len = 1;
            while (visited.count(v + len)) { len++; }
            maxLen = std::max(maxLen, len);
        }
        return maxLen;
    }
};

// union-find, T: O(na(n)) ~= O(n), S: O(n)

#include <unordered_map>
#include <utility> // std::swap

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        const int n = static_cast<int>(nums.size());
        if (n == 0) { return 0; }

        std::unordered_map<int, int> map; // val: idx
        map.reserve(n);
        map.max_load_factor(0.25f);

        // de-dup nums
        int count = 0;
        for (int i = 0; i < n; i++) {
            auto [it, inserted] = map.try_emplace(nums[i], count);
            if (inserted) { count++; }
        }

        std::vector<int> parent(count);
        std::vector<int> sz(count, 1);
        for (int i = 0; i < count; i++) { parent[i] = i; }

        auto find = [&](int x) {
            while (parent[x] != x) {
                parent[x] = parent[parent[x]];
                x = parent[x];
            }
            return x;
        };

        auto unite = [&](int a, int b) {
            a = find(a); b = find(b);
            if (a == b) { return; }
            if (sz[a] < sz[b]) { std::swap(a, b); }
            parent[b] = a;
            sz[a] += sz[b];
        };

        for (const auto& [val, idx] : map) {
            auto it = map.find(val + 1);
            if (it != map.end()) { unite(idx, it->second); }
        }

        int maxLen = 0;
        for (int i = 0; i < count; i++) {
            if (parent[i] == i) { maxLen = std::max(maxLen, sz[i]); }
        }
        return maxLen;
    }
};
