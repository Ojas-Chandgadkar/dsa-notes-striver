/*
Disjoint Set / Union find :     
    This is used to efficiently find whether two nodes are part of the same component.
    The general idea is to have one node as the representative for that component.
    If two nodes have the same representative, the belong to same component, else not.
    Disjoint set is used over tradional dfs approch, as it is more efficient since it works in constant time.

    Implementation techniques : (Both are almost similar, use any one)
        1. Disjoint Set using rank
        2. Disjoint Set using size

    There are two main functions of Disjoint Set :  
        1. Union(u,v) : Joins the two components together, if their root parent is different. The smaller component gets joined to larger compoennt.
        2. Find(node) : Find the root parent / representative of the node. 

Use : 
    Disjoint set are generally used for solving Graphs problems.   
    They are implemented in graphs that are constantly changing in nature.  
*/



// ======================================================================================
// using RANK 
// ======================================================================================
#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
private : 
    vector<int> rank, parent;                                          
    
public :  
    DisjointSet(int V){
        rank.resize(V+1, 0);                                            // V+1 ensures that this will work for both 0 and 1 indexed graphs.
        parent.resize(V+1);
        for(int i=0; i<=V; i++){
            parent[i] = i;
        }
    }
    
    int findRootParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findRootParent(parent[node]);             // path compression, by updating parent of connected nodes directly to common root parent
    }
    
    void Union(int u, int v){                                           // union by rank
        int root_u = findRootParent(u);
        int root_v = findRootParent(v);
        
        if(root_u == root_v) return;
        else if(rank[root_u] < rank[root_v]) parent[root_u] = root_v;
        else if(rank[root_v] < rank[root_u]) parent[root_v] = root_u;
        else if(rank[root_u] == rank[root_v]){
            parent[root_v] = root_u;
            rank[root_u]++;
        }
    }
};

int main(){
    
    DisjointSet ds(7);
    ds.Union(1, 2);
    ds.Union(2, 3);
    ds.Union(4, 5);
    ds.Union(6, 7);
    ds.Union(5, 6);

    if (ds.findRootParent(3) == ds.findRootParent(7)) cout << "Same\n";
    else cout << "Not same\n";

    ds.Union(3, 7);

    if (ds.findRootParent(3) == ds.findRootParent(7)) cout << "Same\n";
    else cout << "Not same\n";

    return 0;                                                           // output : Same, Not Same
}



// ======================================================================================
// using SIZE
// ======================================================================================

#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
private : 
    vector<int> size, parent;
    
public :  
    DisjointSet(int V){
        size.resize(V+1, 1);
        parent.resize(V+1);
        for(int i=0; i<=V; i++){
            parent[i] = i;
        }
    }
    
    int findRootParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findRootParent(parent[node]);         // path compression
    }
    
    void Union(int u, int v){                                       // union by size
        int root_u = findRootParent(u);
        int root_v = findRootParent(v);
        
        if(root_u == root_v) return;
        else if(size[root_u] < size[root_v]){
            parent[root_u] = root_v;
            size[v] += size[u];
        }
        else if(size[root_v] < size[root_u]){
            parent[root_v] = root_u;
            size[u] += size[v];
        }
        else if(size[root_u] == size[root_v]){
            parent[root_v] = root_u;
            size[u] += size[v];
        }
    }
};

int main(){
    
    DisjointSet ds(7);
    ds.Union(1, 2);
    ds.Union(2, 3);
    ds.Union(4, 5);
    ds.Union(6, 7);
    ds.Union(5, 6);
    // if 3 and 7 same or not
    if (ds.findRootParent(3) == ds.findRootParent(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.Union(3, 7);

    if (ds.findRootParent(3) == ds.findRootParent(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
    
    
    return 0;                                                       // output : Same, Not Same
}