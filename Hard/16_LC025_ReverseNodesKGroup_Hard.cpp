class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp = head;
        int count = 0;

        // Check whether k nodes are available
        while (temp != NULL && count < k) {
            temp = temp->next;
            count++;
        }

        // If fewer than k nodes, return as it is
        if (count < k) {
            return head;
        }

        // Reverse k nodes
        ListNode* prev = NULL;
        ListNode* curr = head;

        for (int i = 0; i < k; i++) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Connect remaining linked list
        head->next = reverseKGroup(curr, k);

        return prev;
    }
};
