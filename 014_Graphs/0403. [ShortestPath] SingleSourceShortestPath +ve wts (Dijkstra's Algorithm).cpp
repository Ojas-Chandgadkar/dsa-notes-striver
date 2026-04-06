/*
You have been given an undirected, connected graph of ‘V’ vertices (labelled from 0 to V-1) and ‘E’ edges. 
Each edge connecting two nodes 'u' and 'v' has a weight denoting the distance between them.
Your task is to find the shortest path distance from the source node 'S' to all the vertices. 
You have to return a list of integers denoting the shortest distance between each vertex and source vertex 'S'.
('edge' contains {u, v, distance} vectors.)

Note:
    1. There are no self-loops(an edge connecting the vertex to itself) in the given graph.
    2. There are no parallel edges i.e no two vertices are directly connected by more than 1 edge.

*/



// Brute Force APPROACH (QUEUE) : ======================================================================================================
vector<int> dijkstra(vector<vector<int>> &edge, int vertices, int edges, int source)                    
{

    vector<int> shortestPath(vertices, INT_MAX);
    vector<vector<pair<int,int>>> graph(vertices);
    queue<int> q;

    for(int i=0; i<edges; i++){
        int u = edge[i][0];
        int v = edge[i][1];
        int wt = edge[i][2];

        graph[u].push_back({v,wt});
        graph[v].push_back({u,wt});
    }

    q.push(source);
    shortestPath[source] = 0;
    while(!q.empty()){
        int parent = q.front();
        q.pop();

        for(auto p : graph[parent]){
            int adj = p.first;
            int wt = p.second;

            if((shortestPath[adj]==INT_MAX) || (shortestPath[adj] > shortestPath[parent]+wt)){
                shortestPath[adj] = shortestPath[parent] + wt;
                q.push(adj);
            }
        }
    }


    return shortestPath;

}


// Optimal APPROACH(PRIORITY-QUEUE)  ======================================================================================================
// same implementation as queue, just give better complexity of O(ELogV)
vector<int> dijkstra(vector<vector<int>> &edge, int vertices, int edges, int source)
{
    // 'edge' contains {u, v, distance} vectors.

    vector<int> shortestPath(vertices, INT_MAX);
    vector<vector<pair<int,int>>> graph(vertices);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;         // Min Heap {wt, v}
    

    for(int i=0; i<edges; i++){
        int u = edge[i][0];
        int v = edge[i][1];
        int wt = edge[i][2];

        graph[u].push_back({v,wt});
        graph[v].push_back({u,wt});
    }

    q.push({0, source});
    shortestPath[source] = 0;
    while(!q.empty()){
        int parent = q.top().second;
        int distUptoParent = q.top().first;
        q.pop();

        for(auto p : graph[parent]){
            int adj = p.first;
            int wt = p.second;

            if((shortestPath[adj]==INT_MAX) || (shortestPath[adj] > distUptoParent +wt)){
                shortestPath[adj] = distUptoParent + wt;
                q.push({shortestPath[adj], adj});
            }
        }
    }


    return shortestPath;

}

// Optimal APPROACH(SET) : ======================================================================================================
// extra, do this later, watch striver video


/*
Dijkstra's Algorithm can handle cyclic graphs.
It cannot handle graph with negative weights, it falls in endless loop.
The Complexities of the approaches : 
    1. Brute force :
    2. Optimal :
*/