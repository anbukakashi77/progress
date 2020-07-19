#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

// init adjacency list for the graph..
vector<int> g[N];
//init visited array..
int vis[N];

void dfs(int node){
	vis[node]=1;
	for(int child : g[node]){
		if(!vis[child])
			dfs(child);
	}
}

// In a single call, dfs samples an entire connected component in O(size)..
// Because of this property, the most basic application of dfs can be..
// counting the number of connected components in a graph.

int32_t main(){	
	//input number of nodes and edges..
	int n,m; cin >> n >> m;
	for(int i=0 ; i<m ; i++){
		//input edges assuming an undirected graph..
		int u,v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	//dfs from root node assume 1 here..
	
	int cc=0;	// init the connected component count..
	for(int i=1 ; i<n+1 ; i++){
		if(!vis[i]){
			dfs(i); cc++;
		}
	}
	cout << cc << endl;
	return 0;
}
