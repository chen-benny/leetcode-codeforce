// iterative in-place, T: O(n), S: O(1)

#include <cstddef>

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* groupPrev = &dummy;

        while (true) {
            // check k nodes exist
            ListNode* kth = getKth(groupPrev, k);
            if (!kth) { break; }

            ListNode* groupNext = kth->next;
            ListNode* curr = groupPrev->next;
            ListNode* prev = groupNext;

            // reverse k nodes
            while (curr != groupNext) {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            // reconnect groupPrev -> kth(new head), old head -> groupNext
            ListNode* oldHead = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = oldHead;
        }

        return dummy.next;
    }

private:
    ListNode* getKth(ListNode* node, int k) {
        while (node && k > 0) {
            node = node->next;
            --k;
        }
        return node;
    }
};

// recursive, T: O(n), S: O(n / k) stack frames

#include <cstddef>

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // check k node exist
        ListNode* curr = head;
        int count = 0;
        while (curr && count < k) {
            curr = curr->next;
            ++count;
        }
        if (count < k) { return head; }

        // reverse k nodes
        ListNode* prev = nullptr;
        curr = head;
        for (int i = 0; i < k; i++) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // connect to recursed remainder
        head->next = reverseKGroup(curr, k); // head is node tail

        return prev; // prev is new head of reverse group
    }
};

/*
   - getKth cost
   - cache behavior
   ? n not divisible by k
*/
