class Solution {
public:

    void DFS(int currVertex, vector<bool> &visited, int N, vector<vector<int>> &adj){
        if(visited[currVertex]) return;

        visited[currVertex] = true;
        for(int i=0; i<N; i++){
            if(adj[currVertex][i]==1)
                DFS(i, visited, N, adj);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int noOfProvinces = 0;
        int N = isConnected.size();
        vector<bool> visited(N);
        
        for(int city=0; city<N; city++){
            if(!visited[city]){
                DFS(city, visited, N, isConnected);
                noOfProvinces++;
            }
        }

        return noOfProvinces;
        
    }
};