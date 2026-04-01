// Given the root of a binary tree, return the level order traversal of its nodes' values. 
// (i.e., from left to right, level by level).

// Example 1:
// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[9,20],[15,7]]




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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> levelorder;
        queue<TreeNode*> q;

        if(root) q.push(root);
        while(!q.empty()){
            int LevelNodes = q.size();

            vector<int> currLevel;
            for(int i=0; i<LevelNodes; i++){
                TreeNode* front = q.front();
                q.pop();

                currLevel.push_back(front->val);

                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }

            levelorder.push_back(currLevel);

        }

        return levelorder;
    }
};