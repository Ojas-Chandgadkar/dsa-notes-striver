/*
Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
        ListNode* middle = head;
        ListNode* fastPtr = head;

        if(head==NULL) return head;

        while(fastPtr && fastPtr->next!=NULL){
            fastPtr = fastPtr->next->next;
            middle = middle->next;
        }

        return middle;
    }
};



// ------------------------------My Solution ------------------------------
// Time -> O(n) 
// Space -> O(1)
// ------------------------------ Approach ------------------------------
// 
// The technique is called 'Slow and Fast Pointers'.
