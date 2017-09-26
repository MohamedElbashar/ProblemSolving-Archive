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
vi dfs_num, dfs_low, S, visited;
vector<vector<int>> AdjList;
vi dfs_low, dfs_num,  articulation_vertex;
int dfsNumberCounter, rootChildren, dfsRoot, V;// global variables
void tarjanSCC(int u) {
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++; // dfs_low[u] <= dfs_num[u]
	S.push_back(u); // stores u in a vector based on order of visitation
	visited[u] = 1;
	for (int j = 0; j < (int) AdjList[u].size(); j++) {
		ii v = AdjList[u][j];
		if (dfs_num[v] == -1)
			tarjanSCC(v);
		if (visited[v]) // condition for update
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}
	if (dfs_low[u] == dfs_num[u]) { // if this is a root (start) of an SCC
		printf("SCC %d:", ++numSCC); // this part is done after recursion
		while (1) {
			int v = S.back();
			S.pop_back();
			visited[v] = 0;
			printf(" %d", v);
			if (u == v)
				break;
		}
		printf("\n");
	}
}
int main() {
	dfs_num.assign(V, -1);
	dfs_low.assign(V, 0);
	visited.assign(V, 0);
	dfsNumberCounter = numSCC = 0;
	for (int i = 0; i < V; i++)
		if (dfs_num[i] == -1)
			tarjanSCC(i);
}
