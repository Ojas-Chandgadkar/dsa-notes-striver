/*
 * Definition for doubly-linked list.
 * class Node
 * {
 * public:
 *    int data;
 *    Node *next, *prev;
 *    Node() : data(0), next(nullptr), prev(nullptr) {}
 *    Node(int x) : data(x), next(nullptr), prev(nullptr) {}
 *    Node(int x, Node *next, Node *prev) : data(x), next(next), prev(prev) {}
 * };
 */

Node* constructDLL(vector<int>& arr) {

    int N = arr.size();

    Node* head = NULL;
    
    Node* curr = NULL;
    for(int i=0; i<N; i++){
        Node *newNode = new Node(arr[i]);
        if(head==NULL){
            head = newNode;
            curr = head;
        }
        else{
            newNode->prev = curr;
            curr->next = newNode;
            curr = newNode;
        }
    }

    return head;
}
