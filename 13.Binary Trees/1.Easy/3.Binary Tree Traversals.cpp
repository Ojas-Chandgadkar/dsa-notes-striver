/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

void InorderTraveral(TreeNode *root, vector<int> &arr){
    if(root == NULL) return;

    InorderTraveral(root->left, arr);
    arr.push_back(root->data);
    InorderTraveral(root->right, arr);
}

void PreorderTraversal(TreeNode* root, vector<int> &arr){
    if(root == NULL) return;

    arr.push_back(root->data);
    PreorderTraversal(root->left, arr);
    PreorderTraversal(root->right, arr);
}

void PostorderTraversal(TreeNode* root, vector<int> &arr){
    if(root == NULL) return;

    PostorderTraversal(root->left, arr); 
    PostorderTraversal(root->right, arr);
    arr.push_back(root->data);
}

vector<vector<int>> getTreeTraversal(TreeNode *root){
    
    vector<vector<int>> traversals(3);

    InorderTraveral(root, traversals[0]);
    PreorderTraversal(root, traversals[1]);
    PostorderTraversal(root, traversals[2]);

    return traversals;
}