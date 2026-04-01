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

    void getInorder(TreeNode* root, vector<int> &arr){
        if(!root) return;

        getInorder(root->left, arr);
        arr.push_back(root->val);
        getInorder(root->right, arr);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> inorder;
        getInorder(root, inorder);

        return inorder;
    }
};