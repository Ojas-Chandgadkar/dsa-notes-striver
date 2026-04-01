/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

void left_boundary(TreeNode<int>* root, vector<int> &res){
    if(root==NULL) return;
    else if(!root->left && !root->right) return;

    res.push_back(root->data);
    
    if(root->left){
        left_boundary(root->left, res);
    }
    else if(root->right){
        left_boundary(root->right, res);
    }
}

void leafs_boundary(TreeNode<int>* root, vector<int> &res){
    if(root==NULL) return;
    if(!root->left && !root->right){
        res.push_back(root->data);
        return;
    }

    leafs_boundary(root->left, res);
    leafs_boundary(root->right, res);

}

void right_boundary(TreeNode<int>* root, vector<int> &res){
    if(root==NULL) return;
    else if(!root->left && !root->right) return;

    if(root->right){
        right_boundary(root->right, res);
    }
    else if(root->left){
        right_boundary(root->left, res);
    }
    res.push_back(root->data);
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
	vector<int> boundary;
    if(!root) return boundary;

    boundary.push_back(root->data);
    left_boundary(root->left, boundary);
    leafs_boundary(root, boundary);
    right_boundary(root->right, boundary);

    return boundary;
}
