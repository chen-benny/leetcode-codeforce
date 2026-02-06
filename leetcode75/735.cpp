#include <vector>

using std::vector;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stk;
        stk.reserve(asteroids.size());

        for (int ast : asteroids) {
            while (!stk.empty() && stk.back() > 0 && ast < 0) {
                if (stk.back() < -ast) {
                    stk.pop_back();
                } else if (stk.back() == -ast) {
                    stk.pop_back();
                    ast = 0;
                    break;
                } else {
                    ast = 0;
                    break;
                }
            }

            if (ast != 0) {
                stk.push_back(ast);
            }
        }

        return stk;
    }
};
