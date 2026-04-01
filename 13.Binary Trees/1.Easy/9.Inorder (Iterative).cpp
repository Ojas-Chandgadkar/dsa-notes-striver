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

    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> inorder;
        stack<TreeNode*> st;

        TreeNode* curr = root;
        while(true){
            while(curr){
                st.push(curr);
                curr = curr->left;
            }
            if(st.empty()) break;

            TreeNode* top = st.top();
            st.pop();
            inorder.push_back(top->val);
            curr = top->right;
        }

        return inorder;
    }
    
};