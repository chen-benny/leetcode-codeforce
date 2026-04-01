// stack, T: O(n), S: O(n)

#include <string>
#include <stack>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> stk;

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                stk.push(c);
            } else {
                if (stk.empty()) { return false; }
                char top = stk.top();
                stk.pop();
                if (c == ')' && top != '(') { return false; }
                if (c == ']' && top != '[') { return false; }
                if (c == '}' && top != '{') { return false; }
            }
        }
        return stk.empty();
    }
};

/*
   - std::stack overhead
   - match-table over if-branches
   ? return st.empty()
   ? O(1) space
*/
