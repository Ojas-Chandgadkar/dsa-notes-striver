vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {

    vector<vector<int>> adj(n);

    for(int i=0; i<n; i++) 
        adj[i].push_back(i);
    
    for(auto edge : edges){
        int x = edge[0];
        int y = edge[1];
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    return adj;
}