/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// OPTIMAL 
class Solution {
public:
    bool hasCycle(ListNode *head) {
    
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast!=NULL && fast->next!=NULL){

            fast = fast->next->next;
            slow = slow->next;

            if(fast==slow)
                return true;
        }

        return false;
    }
};


// NOT OPTIMAL 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        bool is_CyclePresent = false;
        
        ListNode* temp = head;
        set<ListNode*> st;

        while(temp!=NULL){
            if(st.find(temp)!=st.end()){
                is_CyclePresent = true;
                break;
            }
            st.insert(temp);
            temp = temp->next;
        }

        return is_CyclePresent;
    }
};