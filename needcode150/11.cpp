// two-pointers, start from both ends, move the ptr with shorter heights, T: O(n), S: O(1)

#include <vector>
#include <algorithm>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int lo = 0;
        int hi = static_cast<int>(height.size()) - 1;
        int best = 0;

        while (lo < hi) {
            int cur = std::min(height[lo], height[hi]) * (hi - lo);
            best = std::max(best, cur);

            if (height[lo] < height[hi]) { ++lo; }
            else { --hi; }
        }
        return best;
    }
};

/*
   - cache behavior
   - branch prediction
   ? why moving shorter pointer is correct
   ? all heights are equal
   ? extend to 3D
*/
