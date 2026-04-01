
// using Topological Sort (BFS) ============================================================================================================================

#include<bits/stdc++.h>

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    
    vector<vector<int>> graph(n+1);
    vector<int> topologicalOrder;
    vector<int> indegree(n+1, 0);
    vector<int> visited(n+1, false);
    queue<int> q;

    for(int i=0; i<edges.size(); i++){
        graph[edges[i].first].push_back(edges[i].second);
    }

    for(int i=1; i<=n; i++){
        for(auto adj : graph[i]){
            indegree[adj]++;
        }
    }

    for(int i=1; i<=n; i++){
        if(indegree[i]==0){
            q.push(i);
            visited[i] = true;
        }
    }

    while(!q.empty()){
        int vertex = q.front();
        q.pop();

        topologicalOrder.push_back(vertex);

        for(auto adj : graph[vertex]){
            indegree[adj]--;

            if(!visited[adj] && indegree[adj]==0){
                q.push(adj);
                visited[adj] = true;
            }
        }
    }

    
    return(topologicalOrder.size() == n) ? 0 : 1;
}