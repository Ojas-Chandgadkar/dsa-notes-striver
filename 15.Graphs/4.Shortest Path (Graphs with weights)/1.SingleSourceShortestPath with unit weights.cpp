
/*
You are given an undirected graph with 'N' nodes and 'M' edges. 
The weight of each edge in the graph is one unit.
Given a source vertex 'src', you must return an array 'answer' of length 'N', 
where 'answer[i]' is the shortest path length between the source vertex 'src' and 'i'th vertex.
Note: All the nodes are zero-based.

Example:
    Input:N=5, M=5
    Edges=[(0, 1), (1, 4), (2, 3), (2, 4), (3, 4)], src=1 
    Output: 1 0 2 2 1

*/


vector<int> shortestPath(int n, vector<vector<int>>&edges, int src) {

    vector<int> shortestDist(n, -1);
    vector<vector<int>> graph(n);
    queue<int> q;

    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int currDist = 0;
    q.push(src);
    while(!q.empty()){
        int qSize = q.size(); 
        
        for(int i=0; i<qSize; i++){
            int front = q.front();
            q.pop();
            if((shortestDist[front]==-1) || (shortestDist[front]!=-1 && shortestDist[front]>currDist)){
                shortestDist[front] = currDist;
            }

            for(auto adj : graph[front]){
                if(shortestDist[adj]==-1) q.push(adj);
            }
        }

        currDist++;
    }


    return shortestDist;
}