class Graph {

public:

    bool dfs_cycleChecker(int currV, int parent, vector<bool> &visited, vector<int> graph[]){
        
        visited[currV] = true;

        for(int i=0; i<graph[currV].size(); i++){
            int adj = graph[currV][i];

             if(!visited[adj]) {
                if (dfs_cycleChecker(adj, currV, visited, graph))
                    return true;
            } 
            else if(visited[adj] && adj!=parent){
                return true;
            }
        }

        return false;
    }


    bool detectCycle(int V, vector<int> adj[]) {
        
        bool is_cyclePresent = false;
        vector<bool> visited(V, false);

        for(int i=0; i<V; i++){
            if(!visited[i]){
                is_cyclePresent = dfs_cycleChecker(i, -1, visited, adj);
                if(is_cyclePresent) break;
            }
        }
        

        return is_cyclePresent;
    }
};