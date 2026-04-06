// } Driver Code Ends
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> topview;
        
        queue<pair<int,Node*>> q;                 // Queue <horizontalDistance, value>
        
        if(root) q.push({0, root});
        else return topview;
        
        map<int, int> HdMap;                      // Map <horizontalDistance,  value>
        while(!q.empty()){
            int totalParents = q.size();
            
            for(int i=0; i<totalParents; i++){
                int parentHd = q.front().first;
                Node* parentNode = q.front().second;
                q.pop();
                
                if(!HdMap[parentHd]){
                    HdMap[parentHd] = parentNode->data;
                }
                
                if(parentNode->left) q.push({parentHd - 1, parentNode->left});
                if(parentNode->right) q.push({parentHd + 1, parentNode->right});
            }
        }
        
        for(auto val : HdMap){
            topview.push_back(val.second);
        }
        
        return topview;
    }

};

