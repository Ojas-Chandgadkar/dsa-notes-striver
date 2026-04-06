class Graph {

public:

    bool bfs_cycleChecker(int startV, int &totalV, vector<bool> &visited, vector<int> graph[]){

        bool is_cycleDetected = false;

        queue<pair<int,int>> q;
        q.push({startV, -1});                                   // {currV, parent}
        visited[startV] = true;

        while(!q.empty()){
            pair<int,int> front = q.front();
            int currV = front.first;
            int parentV = front.second;
            q.pop();

            int totalConnected = graph[currV].size();

            for(int i=0; i<totalConnected; i++){
                int adj = graph[currV][i];

                if(!visited[adj]){
                    q.push({adj, currV});
                    visited[adj] = true;
                }
                else if(visited[adj] && adj!=parentV){
                    is_cycleDetected = true;
                    break;
                }
            }    
        }

        return is_cycleDetected;
    }

    bool detectCycle(int V, vector<int> adj[]) {
        
        bool is_cyclePresent = false;
        vector<bool> visited(V, false);

        for(int i=0; i<V; i++){
            if(!visited[i]){
                is_cyclePresent = bfs_cycleChecker(i, V, visited, adj);
                if(is_cyclePresent) break;
            }
        }
        

        return is_cyclePresent;
    }
};