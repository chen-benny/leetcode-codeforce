#include <vector>
#include <unordered_set>

using std::vector;
using std::unordered_set;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> visited;
        visited.reserve(nums.size());

        for (int val : nums) {
            if (!visited.insert(val).second) {
                return true;
            }
        }
        return false;
    }
};

// follow-up: O(1) space

#include <algorithm>

using std::sort;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) {
                return true;
            }
        }
        return false;
    }
};
