// two-pointers, T: O(n), S: O(1)

#include <string>
#include <cctype>

class Solution {
public:
    bool isPalindrome(std::string s) {
        int lo = 0;
        int hi = static_cast<int>(s.size()) - 1;

        while (lo < hi) {
            while (lo < hi && !std::isalnum(s[lo])) { ++lo; }
            while (lo < hi && !std::isalnum(s[hi])) { --hi; }
            if (std::tolower(s[lo]) != std::tolower(s[hi])) { return false; }
            ++lo;
            --hi;
        }
        return true;
    }
};

/*
   - ASCII vs UTF-8 for std::isalnum / std::tolower
   - cache behavior
   - branch prediction
   ? why not build a filtered string first
   ? handle unicode
*/
