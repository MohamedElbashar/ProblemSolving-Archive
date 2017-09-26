#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define PI 3.1415926535897932384626433832795
#define ll long long
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define mem(a,b) memset(a,b,sizeof a)
#define oo 1e8
#define sz(v) ((int)((v).size()))
#define minn(a, b, c) min(min(a, b), c)
#define maxx(a, b, c) max(max(a, b), c)
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int di[] = { 1, -1, 0, 0 };
int dj[] = { 0, 0, 1, -1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	// online submission
	//freopen("interesting.in", "r", stdin);
#endif
}
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\/\/\/\/\/\/
vector<vector<int>> AdjList;
vi dfs_low, dfs_num, dfs_parent, articulation_vertex;
int dfsNumberCounter, rootChildren, dfsRoot, V;
void ArticPointAndBridge(int u) {
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;  // dfs_low[u] <= dfs_num[u]
	for (int i = 0; i < sz(AdjList[u]); i++) {
		int v = AdjList[u][i];
		if (dfs_num[v] == -1) {  // a tree edge
			dfs_parent[v] = u;
			if (u == dfsRoot)
				rootChildren++;   // special case if u is a root
			ArticPointAndBridge(v);
			if (dfs_low[v] >= dfs_num[u])  // for articulation point
				articulation_vertex[u] = true;  // store this information first
			if (dfs_low[v] > dfs_num[u])    // for bridge
				printf(" Edge (%d, %d) is a bridge\n", u, v);
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);  // update dfs_low[u]
		} else if (v != dfs_parent[u]) {  // a back edge and not direct cycle
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);   // update dfs_low[u]
		}

	}
}
int main() {
	file();
	dfsNumberCounter = 0;
	dfs_num.assign(V, -1);
	dfs_low.assign(V, 0);
	dfs_parent.assign(V, 0);
	articulation_vertex.assign(V, 0);


	//Enter Graph  in AdjList


	printf("Bridges:\n");
	for (int i = 0; i < V; i++) {
		if (dfs_num[i] == -1) {
			dfsRoot = i;
			rootChildren = 0;
			ArticPointAndBridge(i);
			articulation_vertex[dfsRoot] = (rootChildren > 1);   // special case
		}
	}
	printf("Articulation Points:\n");
	for (int i = 0; i < V; i++)
		if (articulation_vertex[i])
			printf(" Vertex %d\n", i);

}
