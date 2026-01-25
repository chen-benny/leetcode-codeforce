class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        /*
         * Return true if all freqs of val is uniq in arr
         *
         * hash-map: val to count, hash-set: count
         */
        unordered_map<int, int> freq;
        for (int num : arr) {
            ++freq[num];
        }

        unordered_set<int> seen;
        for (auto& [num, cnt] : freq) {
            if (seen.count(cnt)) {
                return false;
            }
            seen.insert(cnt);
        }

        return true;
    }
};
