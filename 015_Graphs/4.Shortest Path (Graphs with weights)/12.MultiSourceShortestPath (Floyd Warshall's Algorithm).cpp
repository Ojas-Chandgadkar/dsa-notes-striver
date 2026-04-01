/*
You have been given a directed weighted graph of ‘N’ vertices labeled from 1 to 'N' and ‘M’ edges. 
Each edge connecting two nodes 'u' and 'v' has a weight 'w' denoting the distance between them.
Your task is to find the length of the shortest path between the ‘src’ and ‘dest’ vertex given to you in the graph using Flloyd warshall’s algorithm. 
The graph may contain negatively weighted edges.

Note :
    It's guaranteed that the graph doesn't contain self-loops and multiple edges. Also the graph does not contain negative weight cycles.
    Detailed explanation ( Input/output format, Notes, Images )

*/


int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {

    int INF = 1e9;
    vector<vector<int>> dist(n+1, vector<int>(n+1, INF));                        // adjMatrix

    for(int i=0; i<=n; i++){
        dist[i][i] = 0;
    }
    for(int i=0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        dist[u][v] = wt;
    }


    for(int via=1; via<=n; via++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if (dist[i][via] != INF && dist[via][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][via]+dist[via][j]);
                }
            }
        }
    }
    

    return dist[src][dest];
}

/*
At last run a for loop, 
if dist[i][i] is less than 0 for any i, we can say there exists a negative cycle.
*/