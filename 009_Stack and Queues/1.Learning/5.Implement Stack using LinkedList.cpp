/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };


*****************************************************************/

class Stack
{
private : 
    Node* top;
    int size;

public:
    Stack()
    {
        top = NULL;
        size = 0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        if(size==0) return true;
        return false;
    }

    void push(int data)
    {
        Node* newNode = new Node(data);
        
        if(top == NULL) top = newNode;
        else{
            newNode->next = top;
            top = newNode;
        }
        size++;
    }

    void pop()
    {
        if(isEmpty()) return;

        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
    }

    int getTop()
    {
        if(isEmpty()) return -1;
        return top->data;
    }
};