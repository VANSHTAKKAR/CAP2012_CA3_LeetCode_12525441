class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode dummy(0);
        dummy.next = head;

        ListNode* slow = &dummy;
        ListNode* fast = &dummy;

        // Move fast pointer n steps forward
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // Move both pointers
        while (fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        // Remove the required node
        slow->next = slow->next->next;

        return dummy.next;
    }
};
