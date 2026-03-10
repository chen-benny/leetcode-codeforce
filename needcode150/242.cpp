#include <string>
#include <algorithm>

using std::string;
using std::sort;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) { return false; }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

// follow-up: freq counting

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) { return false; }
        int freq[26] = {};

        for (char ch : s) { ++freq[ch-'a']; }
        for (char ch : t) { --freq[ch-'a']; }
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) { return false; }
        }
        return true;
    }
};
