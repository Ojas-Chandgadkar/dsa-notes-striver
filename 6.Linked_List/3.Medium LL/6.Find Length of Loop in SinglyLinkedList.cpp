/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 * };
 *
 *************************************************************************/

int lengthOfLoop(Node *head) {

    Node* slow = head;
    Node* fast = head;
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
        int length = 1;
        slow = slow->next;
        while(slow!=fast){
            length++;
            slow = slow->next;
        }
        return length;

    }
    else{
        return 0;
    }
}
