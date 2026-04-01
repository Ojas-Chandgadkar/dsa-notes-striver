// struct Node
// {
//     int data;
//     Node* left;
//     Node* right;
// };

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        
        vector<int> bottomview;
        queue<pair<int, Node*>> q; 
        map<int, int> HD_map;
        
        if(root) q.push({0, root});
        
        while(!q.empty()){
            int totalParents = q.size();
            
            for(int i=0; i<totalParents; i++){
                int parentHd = q.front().first;
                Node* parentNode = q.front().second;
                q.pop();    
                
                HD_map[parentHd] = parentNode->data;
                
                if(parentNode->left) q.push({parentHd - 1, parentNode->left});
                if(parentNode->right) q.push({parentHd + 1, parentNode->right});
            }
        }
        
        for(auto val : HD_map){
            bottomview.push_back(val.second);
        }
        
        
        
        return bottomview;
    }
};