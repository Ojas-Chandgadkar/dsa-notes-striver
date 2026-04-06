vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    
    vector<int> bfs;
    queue<int> q;
    vector<bool> visited(n);

    if(n>0){
        q.push(0);
        visited[0] = true;
    }
    else return bfs;


    while(!q.empty()){
        int U = q.front();
        q.pop();
        bfs.push_back(U);

        for(int i=0; i<adj[U].size(); i++){
            int V = adj[U][i];

            if(!visited[V]){
                q.push(V);
                visited[V] = true;
            } 
        }
    }


    return bfs;

}