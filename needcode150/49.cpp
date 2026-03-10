#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using std::vector;
using std::string;
using std::unordered_map;
using std::sort;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups; // sorted-word : {word...}
        for (const string& word : strs) {
            string key = word;
            sort(key.begin(), key.end());
            groups[key].push_back(word);
        }

        vector<vector<string>> res;
        res.reserve(groups.size());
        for (auto& [key, group] : groups) {
            res.push_back(std::move(group));
        }
        return res;
    }
};

// follow-up: freq-counting

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (const string& word : strs) {
            string key = make_key(word);
            groups[key].push_back(word);
        }

        vector<vector<string>> res;
        res.reserve(groups.size());
        for (auto& [key, group] : groups) {
            res.push_back(std::move(group));
        }
        return res;
    }

private:
    string make_key(const string& word) {
        int freq[26] = {};
        for (char ch : word) { ++freq[ch-'a']; }
        string key;
        key.reserve(52); // worst case: 26 letter + 26 delimiters
        for (int i = 0; i < 26; i++) {
            key += static_cast<char>('a' + i);
            key += static_cast<char>(freq[i]);
        }
        return key;
    }
};
