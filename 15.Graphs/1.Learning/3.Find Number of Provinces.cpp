// Find the Number of Provinces

// Problem statement
// You are given 'n'cities, some of which are connected by bidirectional roads. You
// are also given an 'n x n' matrix i.e. 'roads', where if city 'i' and 'j' are connected
// by a road then 'roads [i][j]'= 1, otherwise 'roads[i][j]' = 0.

// Example:
// n = 4, roads = [ [1, 1, 1, 0],
// [1, 1, 1, 0],
// [1, 1, 1, 0],
// [0, 0, 0, 1]]
// A province is a group of cities that are either directly or indirectly connected to
// each other through roads.
// The goal is to count and return the total number of such provinces in the given
// matrix. 



void DFS(int currVertex, vector<vector<int>> &adj, int N, vector<bool> &visited){
    if(visited[currVertex]) return;

    visited[currVertex] = true;
    for(int i=0; i<N; i++){
        if(adj[currVertex][i]==1)
            DFS(i, adj, N, visited);
    }
}

int findNumOfProvinces(vector<vector<int>>& roads, int n) {

    int noOfProvinces = 0;

    vector<bool> visited(n);
    for(int city=0; city<n; city++){
        if(!visited[city]){
            DFS(city, roads, n, visited);
            noOfProvinces++;
        }
    }

    return noOfProvinces;
}

