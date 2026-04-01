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

// OPTIMAL 


// NOT OPTIMAL 
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        
        multiset<int> st;
        ListNode* temp = head;

        while(temp){
            st.insert(temp->val);
            temp = temp->next;
        }

        temp = head;
        set<int> :: iterator it;
        it = st.begin();
        while(temp){
            temp->val = *it;
            temp = temp->next;
            it++;
        }

        return head;
    }
};