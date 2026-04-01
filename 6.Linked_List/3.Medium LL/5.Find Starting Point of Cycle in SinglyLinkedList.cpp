/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        ListNode* slow = head;
        ListNode* fast = head;
        bool is_cyclePresent = false;

        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow==fast){
                is_cyclePresent = true;
                break;
            }
        }

        if(is_cyclePresent){
            ListNode* start = head;
            while(start!=slow){
                start = start->next;
                slow  = slow->next;
            }
            return start;
        }
        else{
            return NULL;
        }


    }
};


// ------------------------------My Solution ------------------------------
// Time -> O(n) 
// Space -> O(1)
// ------------------------------ Approach ------------------------------
// 
//