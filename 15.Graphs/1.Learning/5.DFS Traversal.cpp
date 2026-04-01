// For given undirected graph number of 'V' and 'E' are given.
// Also 'edges' are given in where 'edges[i][0]' and edges[i][1]' denotes a signle edge
// Return the DFS traversal in ascending order, also consider for discontinours graphs.



void DFS(int currVertex, vector<vector<int>> &edges, vector<bool> &visited, vector<int> &res){
    if(visited[currVertex]) return;

    visited[currVertex] = true;
    res.push_back(currVertex);
    
    for(int adj=0; adj<edges[currVertex].size(); adj++){
        DFS(edges[currVertex][adj], edges, visited, res);
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> dfs;
    vector<vector<int>> adj(V);
    vector<bool> visited(V);

    for(auto edge : edges){
        int x = edge[0];
        int y = edge[1];
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i=0; i<V; i++){
        if(!visited[i]){
            vector<int> currGraph;
            DFS(i, adj, visited, currGraph);
            dfs.push_back(currGraph);
        }
    }

    return dfs;
}