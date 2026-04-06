/*

You are given a directed acyclic graph of 'N' vertices(0 to 'N' - 1) and 'M' weighted edges.
Return an array that stores the distance(sum of weights) of the shortest path from vertex 0 to all vertices, 
and if it is impossible to reach any vertex, then assign -1 as distance.

For Example:
    Input : N=3, M=3, edges=[0, 1, 2], [1, 2, 3], [0, 2, 6]].
    Output : [0, 2, 5].

*/


void dfs_topoHelper(int vertex, vector<bool> &visited, vector<int> &sorted, vector<vector<pair<int,int>>> &graph){
    visited[vertex] = true;

    for(auto pair : graph[vertex]){
        int adj = pair.first;
        if(!visited[adj]) dfs_topoHelper(adj, visited, sorted, graph);
    }

    sorted.push_back(vertex);
}

vector<int> get_toposort(int start, vector<vector<pair<int,int>>> &graph){
    vector<int> sorted;
    vector<bool> visited(graph.size(), false);
    dfs_topoHelper(start, visited, sorted, graph);

    reverse(sorted.begin(), sorted.end());
    return sorted;
}

vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    vector<int> minDist(n, -1);
    vector<vector<pair<int,int>>> graph(n);
    vector<int> topologicalOrder;

    for(int i=0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        graph[u].push_back({v, wt});
    }

    topologicalOrder = get_toposort(0, graph);

    minDist[0] = 0;
    for(auto parent : topologicalOrder){
        for(auto pair : graph[parent]){
            int adj = pair.first;
            int wt = pair.second;

            if((minDist[adj]==-1) || (minDist[adj]!=-1 && minDist[adj]>minDist[parent]+wt)){
                minDist[adj] = minDist[parent] + wt;
            } 
        }
    }


    return minDist;
}


/*
1. Toplogical sort
2. Edge relaxation
*/