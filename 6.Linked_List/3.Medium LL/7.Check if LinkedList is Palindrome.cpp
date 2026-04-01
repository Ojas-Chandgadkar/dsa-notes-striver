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
    bool isPalindrome(ListNode* head) {
        if(head==NULL && head->next==NULL) return true;

        bool is_palindrome = true;
        ListNode* slow = head;
        ListNode* fast = head;

        //finding the middle of LL
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        //reversing the secondhalf
        ListNode* secondHalf = slow->next;
        slow->next = NULL;
        ListNode* prev = NULL;
        ListNode* curr = secondHalf;
        ListNode* next = NULL;
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        } 

        //compare both halves
        ListNode* firstHalf = head;
        secondHalf = prev;
        while(secondHalf!=NULL){
            if(firstHalf->val != secondHalf->val){
                is_palindrome = false;
                break;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        return is_palindrome;
    }
};


// ------------------------------My Solution ------------------------------
// Time -> O(n) 
// Space -> O(1)
// ------------------------------ Approach ------------------------------
// 
// 
