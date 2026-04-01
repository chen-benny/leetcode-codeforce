// auxiliary-min-stack, T: O(1) all ops, S: O(n)

#include <stack>
#include <climits>
#include <algorithm>

class MinStack {
    std::stack<int> stk;
    std::stack<int> minStk; // top = cur min

public:
    MinStack() {}

    void push(int val) {
        stk.push(val);
        minStk.push(minStk.empty() ? val : std::min(val, minStk.top()));
    }

    void pop() {
        stk.pop();
        minStk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return minStk.top();
    }
};

// single-stack with encoded delta, T: O(1) all ops, S: O(n)

#include <stack>
#include <climits>
#include <algorithm>

class MinStack {
    std::stack<long long> stk; // stores delta = val - prevMin
    long long curMin;

public:
    MinStack() : curMin(INT_MIN) {}

    void push(int val) {
        if (stk.empty()) {
            stk.push(0LL);
            curMin = val;
        } else {
            long long delta = static_cast<long long>(val) - curMin;
            stk.push(delta);
            if (delta < 0) { curMin = val; }
        }
    }

    void pop() {
        long long delta = stk.top();
        stk.pop();
        if (delta < 0) { curMin -= delta; } // restore prev min
    }

    int top() {
        long long delta = stk.top();
        return static_cast<int>(delta < 0 ? curMin : curMin + delta);
    }

    int getMin() {
        return static_cast<int>(curMin);
    }
};


/*
   - long long for delta
   - delta decoding
   - auiliary-stack vs delta-decoding
   ? O(1) space
   ? dup mins
   ? flat-array
*/
