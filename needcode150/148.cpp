// top-down merge sort, T: O(n * log(n)), S: O(log(n)) stack frames

#include <cstddef>

class Solution {
private:
    ListNode* merge(ListNode* l1, ListNode* l2) {
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

    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next; // fast starts one ahead
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) { return head; }

        ListNode* mid  = getMid(head);
        ListNode* right = mid->next;
        mid->next = nullptr; // cut

        ListNode* l = sortList(head);
        ListNode* r = sortList(right);

        return merge(l, r);
    }
};

// bottom-up merge sort, T: O(n * log(n)), S: O(1)

#include <cstddef>

class Solution {
private:
    ListNode* merge(ListNode* l1, ListNode* l2) {
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

    // split: cut list after `size` nodes, return head of remainder
    ListNode* split(ListNode* head, int size) {
        for (int i = 1; i < size && head; ++i) { head = head->next; }
        if (!head) { return nullptr; }
        ListNode* rest = head->next;
        head->next = nullptr;
        return rest;
    }

public:
    ListNode* sortList(ListNode* head) {
        int n = 0;
        for (ListNode* curr = head; curr; curr = curr->next) { ++n; }

        ListNode dummy(0);
        dummy.next = head;

        for (int size = 1; size < n; size *= 2) {
            ListNode* curr = dummy.next;
            ListNode* tail = &dummy;

            while (curr) {
                ListNode* left = curr;
                ListNode* right = split(left, size);
                curr = split(right, size);
                tail->next = merge(left, right);
                while (tail->next) { tail = tail->next; }
            }
        }
        return dummy.next;
    }
};

/*
   - topdown vs bottom-up
   - fast = head->next in getMid
   - tail advancement after merge
   - cache behavior
   ? quicksort
   ? tail advancement
*/
