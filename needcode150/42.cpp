// prefix max arrays, T: O(n), S: O(n)

#include <vector>
#include <algorithm>

class Solution {
public:
    int trap(std::vector<int>& height) {
        int n = static_cast<int>(height.size());
        std::vector<int> leftMax(n);
        std::vector<int> rightMax(n);

        leftMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = std::max(leftMax[i - 1], height[i]);
        }

        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = std::max(rightMax[i + 1], height[i]);
        }

        int water = 0;
        for (int i = 0; i < n; i++) {
            water += std::min(leftMax[i], rightMax[i]) - height[i];
        }
        return water;
    }
};

// monotonic-stack, process left to right, for a taller bar, pop shorter to compute water between, T: O(n), S: O(n)

#include <vector>
#include <stack>
#include <algorithm>

class Solution {
public:
    int trap(std::vector<int>& height) {
        int n = static_cast<int>(height.size());
        std::stack<int> stk; // indices, monotonically decreasing heights
        int water = 0;

        for (int i = 0; i < n; i++) {
            while (!stk.empty() && height[i] > height[stk.top()]) {
                int mid = stk.top();
                stk.pop();
                if (stk.empty()) { break; }
                int width = i - stk.top() - 1;
                int bound = std::min(height[i], height[stk.top()]) - height[mid];
                water += width * bound;
            }
            stk.push(i);
        }
        return water;
    }
};

// two-pointers, the side with smaller max determines the water, proceed that side inward, T: O(n), S: O(1)

#include <vector>
#include <algorithm>

class Solution {
public:
    int trap(std::vector<int>& height) {
        int lo = 0;
        int hi = static_cast<int>(height.size()) - 1;
        int leftMax = 0;
        int rightMax = 0;
        int water = 0;

        while (lo < hi) {
            if (height[lo] < height[hi]) {
                if (height[lo] >= leftMax) { leftMax = height[lo]; }
                else { water += leftMax - height[lo]; }
                ++lo;
            } else {
                if (height[hi] >= rightMax) { rightMax = height[hi]; }
                else { water += rightMax - height[hi]; }
                --hi;
            }
        }
        return water;
    }
};

/*
   - cache behavior
   - monotonic stack - flat array replacement
   - two-pointer correctness
   ? why monotonic stack stores indices
   ? prefix max vs two pointers
   ? extend to 2D
*/
