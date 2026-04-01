#include<bits/stdc++.h>

vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {

    vector<int> topologicalOrder;   
    vector<vector<int>> adjList(nodes);
    vector<int> indegree(nodes, 0);
    queue<int> q;

    for(int i=0; i<edges; i++){
        int u = graph[i][0];
        int v = graph[i][1];

        adjList[u].push_back(v);
    }

    for(int i=0; i<nodes; i++){
        for(auto adj : adjList[i]){
            indegree[adj]++;
        }
    }

    for(int i=0; i<nodes; i++){
        if(indegree[i]==0) q.push(i);
    }

    while(!q.empty()){
        int vertex = q.front();
        topologicalOrder.push_back(vertex);
        q.pop();

        for(auto adj : adjList[vertex]){
            indegree[adj]--;
            if(indegree[adj]==0) q.push(adj);
        }
    }

    return topologicalOrder;
}
