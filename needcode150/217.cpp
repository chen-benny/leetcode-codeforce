// sort, T: O(nlogn), S: O(1)

#include <vector>
#include <algorithm>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        for(int i = 1; i < static_cast<int>(nums.size()); i++) {
            if (nums[i] == nums[i - 1]) { return true; }
        }
        return false;
    }
};

// hash-set, T: O(n), S: O(n)

#include <vector>
#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> visited;
        visited.reserve(nums.size());
        visited.max_load_factor(0.25f);
        for (int val : nums) {
            if (!visited.insert(val).second) { return true; }
        }
        return false;
    }
};

/*
   - cache behavior
   - sort vs hash-set tradeoff
   - hot-path allocation

   ? insert().second instead of find then insert
   ? when prefer sort over hash-set in production
*/
