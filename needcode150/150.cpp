// stack, T: O(n), S: O(n)

#include <vector>
#include <string>
#include <stack>

class Solution {
public:
    int evalRPN(std::vector<std::string>& token) {
        std::stack<long long> stk;

        for (auto& tok : token) {
            if (tok == "+" || tok == "-" || tok == "*" || tok == "/") {
                long long b = stk.top();
                stk.pop();
                long long a = stk.top();
                stk.pop();

                if (tok == "+") { stk.push(a + b); }
                else if (tok == "-") { stk.push(a - b); }
                else if (tok == "*") { stk.push(a * b); }
                else { stk.push(a / b); }
            } else {
                stk.push(std::stoll(tok));
            }
        }
        return static_cast<int>(stk.top());
    }
};

/*
   - long long for intermediate vals
   - std::stack overhead
   - operator size check
   ? pop b before a
   ? without stack
*/
