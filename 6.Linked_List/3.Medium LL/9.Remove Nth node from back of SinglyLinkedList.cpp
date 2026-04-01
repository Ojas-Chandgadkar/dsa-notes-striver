class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return nullptr;

        // Create a dummy node to handle the case where we need to delete the head
        ListNode dummy(0);
        dummy.next = head;

        ListNode* slow = &dummy;
        ListNode* fast = &dummy;

        // Move the fast pointer n+1 positions ahead
        for (int i = 0; i < n + 1; i++) {
            if (fast) fast = fast->next;
            else return nullptr;  // n is out of range
        }

        // Move both pointers until the fast pointer reaches the end
        while (fast) {
            slow = slow->next;
            fast = fast->next;
        }

        // Now slow is pointing to the (n-1)th node from the end
        // Adjust the links to remove the nth node from the end
        slow->next = slow->next->next;

        return dummy.next;
    }
};
