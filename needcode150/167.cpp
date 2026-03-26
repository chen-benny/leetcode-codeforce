// binary-search, for each elem, bin-search its comple in the remaining array, T: O(nlogn), S: O(1)

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        int n = static_cast<int>(numbers.size());
        for (int i = 0; i < n; i++) {
            int comple = target - numbers[i];
            int lo = i + 1;
            int hi = n - 1;

            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (numbers[mid] == comple) { return {i + 1, mid+1}; }
                else if (numbers[mid] < comple) { lo = mid + 1; }
                else { hi = mid - 1; }
            }
        }
        return {};
    }
};

// two-pointers, sorted array, coverge from both ends, T: O(n), S: O(1)

#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        int lo = 0;
        int hi = static_cast<int>(numbers.size()) - 1;

        while (lo < hi) {
            int sum = numbers[lo] + numbers[hi];
            if (sum == target) { return {lo + 1, hi + 1}; }
            else if (sum < target) { ++lo; }
            else { --hi; }
        }
        return {};
    }
};

/*
   - why not hash-map
   - overflow on sum
   - binary-search vs two-pointers
   ? why two pointers correct on a sorted array
   ? with multiple valid pairs
*/
