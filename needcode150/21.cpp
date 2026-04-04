// iterative with dummy head, T: O(m + n), S: O(1)

#include <cstddef>

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        tail->next = list1 ? list1 : list2;

        return dummy.next;
    }
};

// recursive in place merge, T: O(m + n), S: O(m + n) stack allocated

#include <cstddef>

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) { return list2; }
        if (!list2) { return list1; }

        if (list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};

/*
   - dummy head pattern
   - tail->next = list1 ? list1 : list2;
   - cache behavior
   - dummy node on stack vs heap
   ? list1->val <= list2->val
   ? recursive tradeoff
*/
