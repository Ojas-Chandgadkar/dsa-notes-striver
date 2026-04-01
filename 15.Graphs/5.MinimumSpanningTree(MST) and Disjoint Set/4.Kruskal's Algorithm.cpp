class DisjointSet{
private : 
	vector<int> rank;
	vector<int> parent;

public : 
	DisjointSet(int V){
		rank.resize(V+1, 0);
		parent.resize(V+1);
		for(int i=0; i<=V; i++){
			parent[i] = i;
		}
	}

	int get_rootParent(int node){
		if(node==parent[node]) return node;
		return parent[node] = get_rootParent(parent[node]);
	}

	void unionComponents(int u, int v){
		int root_u = get_rootParent(u);
		int root_v = get_rootParent(v);
		
		if(root_u==root_v) return;
		else if(rank[root_u]<rank[root_v]) parent[root_u] = root_v;
		else if(rank[root_v]<rank[root_u]) parent[root_v] = root_u;
		else if(rank[root_u]==rank[root_v]){
			parent[root_v] = root_u;
			rank[u]++;
		}
	}
};
bool cmp(vector<int> a, vector<int> b){
	if(a[2] < b[2]) return true;
	return false;
}

int kruskalMST(int n, vector<vector<int>> &edges)					// edges({u,v,wt})
{
	int mstDist = 0;
	DisjointSet ds(n);

	sort(edges.begin(), edges.end(), cmp);
	for(auto edge : edges){
		int u = edge[0];
		int v = edge[1];
		int wt = edge[2];

		if(ds.get_rootParent(u) != ds.get_rootParent(v)){
			ds.unionComponents(u, v);
			mstDist += wt;
		}
	}

	return mstDist;


}
