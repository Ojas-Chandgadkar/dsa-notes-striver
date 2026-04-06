bool dfs_cycleChecker(int vertex, vector<bool> &visited, vector<bool> &pathVisited, vector<vector<int>> &graph){
    visited[vertex] = true;
    pathVisited[vertex] = true;

    for(auto adj : graph[vertex]){
        if(!visited[adj]){
            if(dfs_cycleChecker(adj, visited, pathVisited, graph)) return true;
        } 
        else if(pathVisited[adj]) return true;
    }
    pathVisited[vertex] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    
    bool is_cyclePresent = false;
    vector<vector<int>> graph(n+1);
    vector<bool> visited(n+1, false);
    vector<bool> pathVisited(n+1, false);

    for(int i=0; i<edges.size(); i++){
        graph[edges[i].first].push_back(edges[i].second);
    }

    for(int i=1; i<=n; i++){
        if(!visited[i]){
            if(dfs_cycleChecker(i, visited, pathVisited, graph)){
                is_cyclePresent = true;
                break;
            }
        }
    }


    return (is_cyclePresent) ? 1 : 0;
}