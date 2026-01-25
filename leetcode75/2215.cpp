class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        /*
         * Return a list answer[] of size 2
         * answer[0]: list of distinct vals in nums1[] but not in nums2[]
         * answer[1]: list of distinct vals in nums2[] but not in nums1[]
         *
         * focus on answer[0]: traverse distinct nums1[], verify if in nums2[] -> hash-set both
         * T: O(n + m), S: O(n + m)
         */
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());

        vector<int> diff1;
        vector<int> diff2;
        diff1.reserve(set1.size()); // answer[0] is at most set1.size(), reserve for optimization
        diff2.reserve(set2.size());

        for (int num1 : set1) {
            if (!set2.count(num1)) {
                diff1.push_back(num1);
            }
        }
        for (int num2 : set2) {
            if (!set1.count(num2)) {
                diff2.push_back(num2);
            }
        }

        return {diff1, diff2};
    }
};

// follow-up: no hash, faster in practice
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        /*
         * no hash overhead, seq mem access for cache
         * two-pointers + sort
         * T: O(nlogn + mlogm), S: O(1)
         */
        sort(nums1.begin(), nums1.end());
        nums1.erase(unique(nums1.begin(), nums1.end()), nums1.end()); // unique on sorted, move to the front, return new end
        sort(nums2.begin(), nums2.end());
        nums2.erase(unique(nums2.begin(), nums2.end()), nums2.end());

        int n1 = nums1.size();
        int i1 = 0;
        int n2 = nums2.size();
        int i2 = 0;
        vector<int> diff1;
        vector<int> diff2;

        while (i1 < n1 || i2 < n2) {
            if (i1 == n1) {
                diff2.push_back(nums2[i2++]);
            } else if (i2 == n2) {
                diff1.push_back(nums1[i1++]);
            } else {
                if (nums1[i1] == nums2[i2]) {
                    ++i1;
                    ++i2;
                } else if (nums1[i1] < nums2[i2]) {
                    diff1.push_back(nums1[i1++]);
                } else {
                    diff2.push_back(nums2[i2++]);
                }
            }
        }

        return {diff1, diff2};
    }
};
