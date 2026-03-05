#include <vector>
#include <unordered_set>
#include <algorithm>

using std::vector;
using std::unordered_set;
using std::push_heap;
using std::pop_heap;
using std::greater;

class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() : next(1) {}

    int popSmallest() {
        if (!heap.empty()) {
            pop_heap(heap.begin(), heap.end(), greater<int>{});
            int val = heap.back();
            heap.pop_back();
            inHeap.erase(val);
            return val;
        }

        return next++;
    }

    void addBack(int num) {
        if (num < next && inHeap.find(num) == inHeap.end()) {
            heap.push_back(num);
            push_heap(heap.begin(), heap.end(), greater<int>{});
            inHeap.insert(num);
        }
    }

private:
    int next;
    vector<int> heap;
    unordered_set<int> inHeap;
};

// follow-up: set (balanced bst)

#include<set>

using std::set;

class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() : next(1) {}

    int popSmallest() {
        if (!addedBack.empty()) {
            int val = *addedBack.begin();
            addedBack.erase(addedBack.begin());
            return val;
        }
        return next++;
    }

    void addBack(int num) {
        if (num < next) { addedBack.insert(num); }
    }

private:
    int next;
    set<int> addedBack;
};
