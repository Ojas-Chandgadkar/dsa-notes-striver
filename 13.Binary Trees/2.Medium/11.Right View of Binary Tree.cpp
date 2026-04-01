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
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> rightview;
        queue<pair<int, TreeNode*>> q;
        map<int,int> HD_map;

        if(root) q.push({0, root});
        else return rightview;
        
        while(!q.empty()){
            int totalParents = q.size();

            for(int i=0; i<totalParents; i++){
                int parentHD = q.front().first;
                TreeNode* parentNode = q.front().second;
                q.pop();

                if(HD_map.find(parentHD)==HD_map.end()) HD_map[parentHD] = parentNode->val;

                if(parentNode->right) q.push({parentHD + 1, parentNode->right});            // line 1
                if(parentNode->left) q.push({parentHD + 1, parentNode->left});              // line 2

            }
        }

        for(auto val : HD_map){
            rightview.push_back(val.second);
        }

        return rightview;
    }
};




// Similary Leftview can be done, by interchanging the order of occurence of 'line 1' and 'line 2'