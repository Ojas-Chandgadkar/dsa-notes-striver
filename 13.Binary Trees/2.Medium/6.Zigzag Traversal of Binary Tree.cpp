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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> zigzag;
        
        queue<TreeNode*> q;
        if(root) q.push(root);

        int dir_LR = true;                          // checks if is "direction Left to Right"
        while(!q.empty()){
            int totalParents = q.size();

            vector<int> parentsArr;
            for(int i=0; i<totalParents; i++){
                TreeNode* parent = q.front();
                q.pop();

                parentsArr.push_back(parent->val);
                
                if(parent->left) q.push(parent->left);
                if(parent->right) q.push(parent->right);

            }
            if(dir_LR) zigzag.push_back(parentsArr);
            else zigzag.push_back(vector<int>(parentsArr.rbegin(), parentsArr.rend()));

            
            dir_LR = ! dir_LR;
        }

        return zigzag;
    }
};