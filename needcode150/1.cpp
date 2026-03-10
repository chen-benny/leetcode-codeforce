#include <vector>

using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = static_cast<int>(nums.size());

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

// follow-up: O(n)
#include <unordered_map>

using std::unordered_map;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = static_cast<int>(nums.size());
        unordered_map<int, int> visited; // val -> idx
        visited.reserve(n);

        for (int i = 0; i < n; i++) {
            int comple = target - nums[i];
            auto it = visited.find(comple);
            if (it != visited.end()) {
                return {it->second, i};
            }
            visited.emplace(nums[i], i);
        }
        return {};
    }
};
