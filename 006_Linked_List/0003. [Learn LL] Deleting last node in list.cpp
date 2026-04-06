/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *deleteLast(Node *list){
    Node *back = list;
    Node *front = list->next;

    while(front->next!=NULL){
        back = front;
        front = front->next;
    }

    delete(front);
    back->next = NULL;

    return list;
}