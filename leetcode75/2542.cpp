#include <vector>
#include <algorithm>
#include <functional>

using std::vector;
using std::sort;
using std::push_heap;
using std::pop_heap;
using std::greater;
using std::max;

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = static_cast<int>(nums1.size());
        vector<int> idx(n);
        for (int i = 0; i < n; i++) { idx[i] = i; }

        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return nums2[a] > nums2[b];
        });

        vector<int> heap;
        heap.reserve(k + 1);
        long long sum = 0;
        long long result = 0;

        for (int i = 0; i < n; i++) {
            int id = idx[i];
            sum += nums1[id];
            heap.push_back(nums1[id]);
            push_heap(heap.begin(), heap.end(), greater<int>{});

            if (static_cast<int>(heap.size()) > k) {
                pop_heap(heap.begin(), heap.end(), greater<int>{});
                sum -= heap.back();
                heap.pop_back();
            }

            if (static_cast<int>(heap.size()) == k) {
                result = max(result, sum * static_cast<long long>(nums2[id]));
            }
        }

        return result;
    }
};
