// iterative, T: O(n), S: O(1)

#include <cstddef>

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

// recursive, T: O(n), S: O(n) stack frames

#include <cstddef>

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) { return head; }
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};

/*
   - prev = nullptr
   - stack depth
   - head->next->next safety
   - cache behavior
*/
