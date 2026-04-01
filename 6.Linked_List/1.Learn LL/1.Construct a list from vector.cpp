/**
 * Definition of linked list
 * class Node {
 *
 * public:
 *     int data;
 *     Node* next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node* next) : data(x), next(next) {}
 * };
 */

Node* constructLL(vector<int>& arr) {
    int N = arr.size();

    Node* head = NULL;
    Node *currPtr = head;
    for(int i=0; i<N; i++){
        Node *newNode = new Node(arr[i]);
        if(head==NULL){
           head = newNode;
           currPtr = newNode;
        }
        else{
            currPtr->next = newNode;
            currPtr = newNode;
        }
    }


    return head;
}