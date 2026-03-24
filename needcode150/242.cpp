// hash-map, T: O(n), S: O(1)

#include <string>
#include <unordered_map>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.size() != t.size()) { return false; }
        std::unordered_map<char, int> freq; // {char: count}

        for (char c : s) { freq[c]++; }
        for (char c : t) {
            if (--freq[c] < 0) { return false; }
        }
        return true;
    }
};

// flat-array, bounded range, T: O(n), S: O(1) stack-allocated

#include <string>
#include <cstring>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.size() != t.size()) { return false; }
        constexpr int ALPHA_SIZE = 26;
        constexpr char BASE_CHAR = 'a';
        
        int freq[ALPHA_SIZE];
        std::memset(freq, 0, sizeof(freq));

        for (char c : s) { freq[c - BASE_CHAR]++; }
        for (char c : t) {
            if (--freq[c - BASE_CHAR] < 0) { return false; }
        }
        return true;
    }
};

/*
   - cache behavior
   - branch prediction

   ? unicode input
   ? one pass solution
*/
