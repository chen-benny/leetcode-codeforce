// hash-map, T: O(n), S: O(n)

#include <vector>
#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> visited; // {val: idx}
        visited.reserve(nums.size());
        visited.max_load_factor(0.25f);

        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            int comp = target - nums[i];
            auto it = visited.find(comp);
            if (it != visited.end()) { return {it->second, i}; }
            visited[nums[i]] = i;
        }
        return {};
    }
};

// constraints: nums[i] in [-10^4, 10^4]
// flat-array, T: O(n), S: O(R), R = value range, stack-allocated

#include <vector>
#include <cstring>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        constexpr int OFFSET = 10001;
        constexpr int RANGE = 20003;
        constexpr int MIN_VAL = -10000;
        constexpr int MAX_VAL = 10000;
        int table[RANGE];
        std::memset(table, -1, sizeof(table));

        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            int comp = target - nums[i];
            if (comp >= MIN_VAL && comp <= MAX_VAL && table[comp + OFFSET] != -1) {
                return {table[comp + OFFSET], i};
            }
            table[nums[i] + OFFSET] = i;
        }
        return {};
    }
};

/*
   - cache behavior
   - hot-path allocation
   - branch prediction
  
   ? when flat array breaks down
   ? why constexpr OFFSET instead of runtime variable
   ? flat_hash_map vs unordered_map with unbounded range
 */
