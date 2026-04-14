 ``` cpp
#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &adjList, int start){
  
  int N = adjList.size();
  stack<int> st;
  vector<bool> visited(N, false);
  
  st.push(start);
  visited[start] = true;

  
  while(!st.empty()){
      int top = st.top();
      cout << top << " ";
      st.pop();
      
      for(int i=0; i<adjList.size(); i++){
          int adj = adjList[top][i];
          
          if(!visited[adj]){
              visited[adj] = true;
              st.push(adj);
          }
      }
  }
  
}

void bfs(vector<vector<int>> &adjList, int start){
    
    int N = adjList.size();
    queue<int> q;
    vector<bool> visited(N);
    
    q.push(start);
    visited[start] = true;
    
    while(!q.empty()){
        int front = q.front();
        cout << front << " ";
        q.pop();
        
        for(int i=0; i<adjList[front].size(); i++){
            int adj = adjList[front][i];
            
            if(!visited[adj]){
                visited[adj] = true;
                q.push(adj);
                
            }
        }
    }
}


void dfsHelper(int vertex, vector<vector<int>> &adjList, vector<bool> &visited){

    visited[vertex] = true;
    cout << vertex << " ";
    
    for(int i=0; i<adjList[vertex].size(); i++){
        int adj = adjList[vertex][i];
        if(!visited[adj]){
            dfsHelper(adj, adjList, visited);
        }
    }
}

void dfs_wrapper(vector<vector<int>> &adjList){
  
    int N = adjList.size();
    vector<bool> visited(N, false);
    
    for(int i=0; i<N; i++){
        if(!visited[i]){
            dfsHelper(i, adjList, visited);
        }
    }
}

int main(){
    
  vector<vector<int>> adjList(5);
  
  adjList[0].push_back(1);
  adjList[0].push_back(2);
  adjList[1].push_back(0);
  adjList[1].push_back(2);
  adjList[1].push_back(3);
  adjList[2].push_back(0);
  adjList[2].push_back(1);
  adjList[2].push_back(4);
  adjList[3].push_back(1);
  adjList[3].push_back(4);
  adjList[4].push_back(2);
  adjList[4].push_back(3);
  
  dfs(adjList, 0);          // Iterative DFS 
  bfs(adjList, 0);          // Iterative BFS
  
  dfs_wrapper(adjList);     // Recursive DFS
  
    
  return 0;
}
 
 
 ```

 ![graph](https://media.geeksforgeeks.org/wp-content/uploads/20221221015614/1-768.png)