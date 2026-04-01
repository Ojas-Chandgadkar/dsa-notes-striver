/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};
*/

Node* createTree(vector<int>&arr){

    int size = arr.size();
    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while(i<size){
        Node* front = q.front();
        q.pop();

        if(i < size){
            front->left = new Node(arr[i]);
            q.push(front->left);
            i++;
        }
        if(i < size){
            front->right = new Node(arr[i]);
            q.push(front->right);
            i++;
        }
    }

    return root;
}