// min-heap, T: O(n * log(k)), S: O(k)

#include <vector>
#include <queue>
#include <cstddef>

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> pq(cmp);

        for (ListNode* node : lists) {
            if (node) { pq.push(node); }
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            tail->next = node;
            tail = tail->next;
            if (node->next) { pq.push(node->next); }
        }

        return dummy.next;
    }
};

// divide-conquer, T: O(n * log(k)), S: O(1)

#include <vector>
#include <cstddef>

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        int n = static_cast<int>(lists.size());
        if (n == 0) { return nullptr; }

        for (int step = 1; step <= n; step *= 2) {
            for (int i = 0; i + step < n; i += 2 * step) {
                lists[i] = mergeTwoLists(lists[i], lists[i + step]);
            }
        }

        return lists[0];
    }

private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;

        return dummy.next;
    }
};

/*
   - heap vs divide-conquer: cache behavior
   - priority_queue with custom comparator
   - if (node) guard
   - divide-conquer in-place
   ? O(nlogk) for both
   ? heap over divide-conquer
*/
