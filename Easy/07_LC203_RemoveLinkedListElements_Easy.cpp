class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        // Remove matching elements from the beginning
        while (head != NULL && head->val == val) {
            head = head->next;
        }

        ListNode* temp = head;

        // Check the remaining linked list
        while (temp != NULL && temp->next != NULL) {

            if (temp->next->val == val) {
                temp->next = temp->next->next;
            }
            else {
                temp = temp->next;
            }
        }

        return head;
    }
};
