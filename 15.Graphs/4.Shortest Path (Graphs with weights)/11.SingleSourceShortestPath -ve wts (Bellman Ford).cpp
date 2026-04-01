/*

Given a weighted and directed graph of V vertices and E edges, 
Find the shortest distance of all the vertex's from the source vertex S. 
If a vertices can't be reach from the S then mark the distance as 10^8. 
Note: If the Graph contains a negative cycle then return an array consisting of only -1.

*/

class Solution {
  public:
    
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        int INF = 1e8;
        vector<int> minDist(V, INF);
        
        minDist[S] = 0;
        for(int i=0; i<V; i++){                                                   // works directly on edges
            for(int j=0; j<edges.size(); j++){
                int src = edges[j][0];
                int adj = edges[j][1];
                int wt = edges[j][2];
    
                if(minDist[src]!=INF && (minDist[adj]>minDist[src]+wt)){
                    minDist[adj] = minDist[src] + wt;
                }
            }
        }
        
        
        bool isCyclePresent = false;
        for(int j=0; j<edges.size(); j++){
            int src = edges[j][0];
            int adj = edges[j][1];
            int wt = edges[j][2];

            if(minDist[src]!=INF && (minDist[adj]>minDist[src]+wt)){
                isCyclePresent = true;
                break;
            }
        }
    
    
        vector<int> minusOne(1,-1);
        return (isCyclePresent)? minusOne : minDist;
    }
};