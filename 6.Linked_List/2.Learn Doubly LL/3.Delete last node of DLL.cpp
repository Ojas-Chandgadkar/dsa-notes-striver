/**
 * Definition of doubly linked list:
 *
 * struct Node {
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() : data(0), prev(nullptr), next(nullptr) {}
 *      Node(int val) : data(val), prev(nullptr), next(nullptr) {}
 *      Node(int val, Node *p, Node *n) : data(val), prev(p), next(n) {}
 * };
 *
 *************************************************************************/

Node * deleteLastNode(Node *head) {
    
    Node *temp = head;

    if(head==NULL){
        return head;
    }
    if(head->next==NULL){
        head = NULL;
        return NULL;
    }


    while(temp->next->next!=NULL){
        temp = temp->next;        
    }
    temp->next = NULL;
    delete(temp->next);

    return head;
}
