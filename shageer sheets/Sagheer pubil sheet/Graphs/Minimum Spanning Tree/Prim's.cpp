#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
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
vi taken;
vector<pi> Adj[1001];
priority_queue<pi> pq;
int u;
int V, E, uu, vv, w;
void process(int vtx) {
	taken[vtx] = 1;
	for (int j = 0; j < sz(Adj[j]); j++) {
		pi v = Adj[vtx][j];
		if (!taken[v.first])
			pq.push(pi(-v.second, -v.first));
	}
}
int main() {
	file();
	taken.assign(V, 0);	 // no vertex is taken at the beginning
	process(0); 	// take vertex 0 and process all edges incident to vertex 0
	int mst_cost = 0;
	while (!pq.empty()) { 	// repeat until V vertices (E=V-1 edges) are taken
		pi front = pq.top();
		pq.pop();
		u = -front.second, w = -front.first; 	// negate the id and weight again
		if (!taken[u]) 	// we have not connected this vertex yet
			mst_cost += w, process(u); 	// take u, process all edges incident to u
	} 	// each edge is in pq only once!
	printf("MST cost = %d (Prim’s)\n", mst_cost);
}
