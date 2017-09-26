#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pi> vpi;
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define mem(a,b) memset(a,b,sizeof a)
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
	//freopen("sets.in", "r", stdin);
#endif
}
//\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\//\/\/\/\/\/\/\/\/\/\/
int n, m, uu, vv, c, cnt;
vpi arr[502], grid[502];
int dis[502];
void dij(int x, int y) {
	priority_queue<pi> q;
	q.push( { 0, x });
	while (!q.empty()) {
		int u = q.top().second;
		int w = q.top().first;
		q.pop();
		if (w > dis[u])
			continue;
		for (int i = 0; i < sz(grid[u]); i++) {
			pi v = grid[u][i];
			if (dis[u] + v.second < dis[v.first]) {
				dis[v.first] = dis[u] + v.second;
				q.push( { -(dis[v.first]), v.first });
			}
		}
	}
}
int main() {
	file();
	while (scanf("%d%d", &n, &m) != EOF) {
//		1. Build the graph using adjacency list.
//		2. Now iterate over all the vertices. For each vertex u, iterate over all its
//		Neighbors. For each neighbor v, iterate over all its neighbours
//		(let them be w1,w2,w3,...). Now create an edge between u and w(i) with
//		the edge cost = cost(u,v) + cost(v,w(i)).
//		3. Why did I do this? Shaon can only traverse a path with even number of edges.
//		So why not create a graph which effectively has even number of edges?
//		Complexity of above step may seems bad but I got a <50 rank so it seems okay.
//		4. Now just apply Djikstra on the new graph created.
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &uu, &vv, &c);
			arr[uu].push_back( { vv, c });
			arr[vv].push_back( { uu, c });
		}
		fill_n(dis, n, INT_MAX);
		for (int i = 0; i < n; i++) {
			for (int u = 0; u < sz(arr[i]); u++) {
				pi cur = arr[i][u];
				for (int v = 0; v < sz(arr[cur.first]); v++) {
					pi vv = arr[cur.first][v];
					grid[i].push_back( { vv.first, (vv.second + cur.second) });
				}
			}
		}
		dis[0] = 0;
		dij(0, 0);
		printf("Set #%d\n", ++cnt);
		if (dis[n - 1] == INT_MAX)
			puts("?");
		else
			printf("%d\n", dis[n - 1]);
		for (int i = 0; i <= n + 1; i++) {
			arr[i].clear(), grid[i].clear();
		}
	}
}

