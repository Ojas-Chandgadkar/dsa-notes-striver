/*

There are n cities connected by some number of flights. You are given an array flights where, 
flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.
You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. 
If there is no such route, return -1. 

Example 1:
    Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
    Output: 700

Example 2:
    Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
    Output: 200
    
Constraints:
    1 <= n <= 100
    0 <= flights.length <= (n * (n - 1) / 2)
    flights[i].length == 3
    0 <= fromi, toi < n
    fromi != toi
    1 <= pricei <= 104
    There will not be any multiple flights between two cities.
    0 <= src, dst, k < n
    src != dst

*/

// BRUTE (Using PriorityQueue) ================================================================================================================
class Solution {
public:

    typedef vector<int> V;

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<int> minPrice(n, -1);
        vector<vector<pair<int,int>>> graph(n);      
        priority_queue<V, vector<V>, greater<V>> pq;       // minHeap : {stopNo, pathCost, city}

        for(int i=0; i<flights.size(); i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];

            graph[u].push_back({v, wt});
        }

        minPrice[src] = 0;
        pq.push({0, 0, src});
        while(!pq.empty()){
            int stopNo = pq.top()[0];
            int pathCost = pq.top()[1];
            int city = pq.top()[2];

            pq.pop();

            for(auto adj : graph[city]){
                int adjCity = adj.first;
                int cost = adj.second;

                if(minPrice[adjCity]==-1 || minPrice[adjCity]>pathCost+cost){
                    minPrice[adjCity] = pathCost + cost;

                    if(stopNo < k) pq.push({stopNo+1, minPrice[adjCity], adjCity});
                }
            }

        }

        return minPrice[dst];      
    }

};


// OPTIMAL (using Queue) ================================================================================================================

class Solution {
public:

    typedef vector<int> V;

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<int> minPrice(n, -1);
        vector<vector<pair<int,int>>> graph(n);      
        queue<V> pq;       // minHeap : {stopNo, pathCost, city}

        for(int i=0; i<flights.size(); i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];

            graph[u].push_back({v, wt});
        }

        minPrice[src] = 0;
        pq.push({0, 0, src});
        while(!pq.empty()){
            int stopNo = pq.front()[0];
            int pathCost = pq.front()[1];
            int city = pq.front()[2];

            pq.pop();

            for(auto adj : graph[city]){
                int adjCity = adj.first;
                int cost = adj.second;

                if(minPrice[adjCity]==-1 || minPrice[adjCity]>pathCost+cost){
                    minPrice[adjCity] = pathCost + cost;

                    if(stopNo < k) pq.push({stopNo+1, minPrice[adjCity], adjCity});
                }
            }

        }

        return minPrice[dst];      
    }

};