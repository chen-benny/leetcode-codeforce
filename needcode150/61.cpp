// find tail + reconnect, T: O(n), S: O(1)

#include <cstddef>

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) { return head; }

        // find length and tail
        int n = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            ++n;
        }

        k %= n;
        if (k == 0) { return head; }

        // find new tail: n - k - 1 steps from head
        ListNode* newTail = head;
        for (int i = 0; i < n - k - 1; ++i) { newTail = newTail->next; }

        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        tail->next = head;

        return newHead;
    }
};

/*
   - k %= n
   - form ring then cut
   - cache behavior
   ? n - k - 1
*/
