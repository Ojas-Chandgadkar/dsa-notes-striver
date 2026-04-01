// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. 
// This path may or may not pass through the root.
// The length of a path between two nodes is represented by the number of edges between them.
 

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
    int height(TreeNode*root, int &maxDiameter){
        if(root==NULL){
            return 0;
        }

        int leftH = height(root->left, maxDiameter);
        int rightH = height(root->right, maxDiameter);

        if(leftH + rightH > maxDiameter) maxDiameter = leftH + rightH;

        return 1 + max(leftH, rightH);


    }

    int diameterOfBinaryTree(TreeNode* root) {

        int diameter = 0;
        height(root, diameter);

        return diameter;
    }
};