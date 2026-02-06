#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    string removeStars(string s) {
        vector<char> stk; // avoid string overhead
        stk.reserve(s.size());

        for (char c : s) {
            if (c == '*') {
                stk.pop_back();
            } else {
                stk.push_back(c);
            }
        }

        return string(stk.begin(), stk.end());
    }
};

// follow-up: in-place
class Solution {
public:
    string removeStars(string s) {
        int write = 0;

        for (int read = 0; read < s.size(); read++) {
            if (s[read] == '*') {
                --write;
            } else {
                s[write++] = s[read];
            }
        }

        return s.substr(0, write);
    }
};
