/*
Given a weighted, undirected, and connected graph of V vertices and E edges. 
The task is to find the sum of weights of the edges of the Minimum Spanning Tree.

Example :
    Input: V = 5,edges = { {0, 1, 2}, {0, 3, 6}, {1, 2, 3}, {1, 3, 8}, {1, 4, 5}, {4, 2, 7}}
    Result: 16
    Explanation: MST = {(0, 1), (0, 3), (1, 2), (1, 4)}


*/

#include<bits/stdc++.h>

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
    int mstDist = 0;
    vector<vector<pair<int,int>>> graph(n);
    vector<bool> visited(n, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;              // mixHeap({dist, vertex})

    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        graph[u].push_back({v,wt});
        graph[v].push_back({u,wt});
    }

    pq.push({0, 0});
    while(!pq.empty()){
        int parent = pq.top().second;
        int wt = pq.top().first;
        
        pq.pop();
        if(visited[parent]) continue;

        visited[parent] = true;
        mstDist += wt;
        for(auto p : graph[parent]){
            int adj = p.first;
            int wt = p.second;

            if(!visited[adj]){
                pq.push({wt, adj});
            }
        }

    }


    return mstDist;
} 



/*
If you want to store MST nodes, make as pq{dist, node, parent}
*/