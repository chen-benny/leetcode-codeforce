// sort as key, T: O(nklogk), S: O(nk)

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> groups;
        for (auto& s : strs) {
            std::string key = s;
            std::sort(key.begin(), key.end());
            groups[key].push_back(s);
        }

        std::vector<std::vector<std::string>> res;
        res.reserve(groups.size());
        for (auto& [key, val] : groups) { res.push_back(std::move(val)); }
        return res;
    }
};

// freq-array as key, T: O(nk), S: O(nk)

#include <vector>
#include <string>
#include <unordered_map>
#include <cstring>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        constexpr int ALPHA_SIZE = 26;
        constexpr char BASE_CHAR = 'a';
        std::unordered_map<std::string, std::vector<std::string>> groups;

        for (auto& s : strs) {
            int freq[ALPHA_SIZE];
            std::memset(freq, 0, sizeof(freq));
            for (char c : s) { freq[c - BASE_CHAR]++; }

            // encode freq-array into fixed-length string key
            std::string key(ALPHA_SIZE, '\0');
            for (int i = 0; i < ALPHA_SIZE; i++) { key[i] = static_cast<char>( freq[i]); }
            groups[key].push_back(s);
        }

        std::vector<std::vector<std::string>> res;
        res.reserve(groups.size());
        for (auto& [key, val] : groups) { res.push_back(std::move(val)); }
        return res;
    }
};

/*
   - cache behavior
   - key encoding

   ? collision risk in key encoding
   ? avoid hash map entirely
*/
