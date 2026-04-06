/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {

        if(root == NULL) return true;

        int leftH = height(root->left);
        int rightH = height(root->right);


        if(abs(leftH-rightH)<=1 & isBalanced(root->left) && isBalanced(root->right)) 
            return true;

        return false;        
        
    }
};



// More optimal ? 
class Solution {
public:
    pair<bool,int> checkbalanced(TreeNode* root){
        if( root == NULL ){
            pair<bool,int> p = make_pair(true, 0);
            return p;
        }
        pair<bool,int> leftans = checkbalanced(root->left);
        pair<bool,int> rightans = checkbalanced(root->right);

        bool op1 = leftans.first;
        bool op2 = rightans.first;
        bool op3 = abs(leftans.second - rightans.second) <= 1;

        pair<bool,int> ans;
        ans.second = max(leftans.second, rightans.second) + 1;
        if(op1 && op2 && op3){
            ans.first = true;
        }
        else{
            ans.first = false;
        }
        return ans;        
    }
    bool isBalanced(TreeNode* root) {
        return checkbalanced(root).first;        
    }
};
