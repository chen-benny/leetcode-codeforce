#include <vector>
#include <utility>

using std::vector;
using std::pair;

class StockSpanner {
public:
    StockSpanner() {}

    int next(int price) {
        int span = 1;
        while (!stk.empty() && stk.back().first <= price) {
            span += stk.back().second;
            stk.pop_back();
        }

        stk.emplace_back(price, span);
        return span;
    }

private:
    vector<pair<int, int>> stk; // (price, span)
};
