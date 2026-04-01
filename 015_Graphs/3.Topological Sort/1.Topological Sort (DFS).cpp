/*
Problem statement
Given a DAG(direct acyclic graph), print Topological Sorting of a given graph

Example :
    1
    5 4
    0 2
    1 2
    3 1
    0 4
    Output : (Correct)
    Explanation: (One correct sort order is : 3 1 0 4 2)

*/

#include<bits/stdc++.h>
using namespace std;

void dfs(int vertex, vector<bool> &visited, vector<int> &topologicalOrder, vector<vector<int>> &adjList){
    visited[vertex] = true;

    for(auto adj : adjList[vertex]){
        if(!visited[adj]) dfs(adj, visited, topologicalOrder, adjList);
    }

    topologicalOrder.push_back(vertex);
}

vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
    
    vector<int> topologicalOrder;
    vector<bool> visited(nodes, false);
    vector<vector<int>> adjList(nodes);
    for(int i=0; i<edges; i++){
        int u = graph[i][0];
        int v = graph[i][1];
        adjList[u].push_back(v);
    }

    for(int i=0; i<nodes; i++){
        if(!visited[i]) dfs(i, visited, topologicalOrder, adjList);
    }

    reverse(topologicalOrder.begin(), topologicalOrder.end());
    return topologicalOrder;
}




/*
Topological sort is only applicable on trees and DAG graph.
*/