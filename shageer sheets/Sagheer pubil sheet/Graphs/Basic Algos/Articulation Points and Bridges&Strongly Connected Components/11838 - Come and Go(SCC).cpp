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
vi arr[2001];
int dfs_num[2001], dfs_low[2001], vis[2001];
vi s;
int n, m, u, v, c, dfsNumberCounter, numSCC;
void dfs(int u) {
	vis[u] = 1;
	s.push_back(u);
	dfs_num[u] = dfs_low[u] = dfsNumberCounter++;
	for (int i = 0; i < sz(arr[u]); i++) {
		if (dfs_num[arr[u][i]] == -1) {
			dfs(arr[u][i]);
		}
		if (vis[arr[u][i]])
			dfs_low[u] = min(dfs_low[u], dfs_low[arr[u][i]]);
	}
	if (dfs_low[u] == dfs_num[u]) {
		while (1) {
			int cur = s.back();
			s.pop_back();
			vis[cur] = 0;
			if (u == cur)
				break;
		}
		numSCC++;
	}
}
int main() {
	file();
	//lazem kolhm ykono fe SCC wa7ed bas 3a4an y2dro ywsl men ay no2ta lltanya
	while (scanf("%d%d", &n, &m) && n) {
		mem(dfs_num,-1), mem(dfs_low, 0), mem(vis, 0);
		dfsNumberCounter = numSCC = 0;
		for (int i = 0; i < n + 1; i++) {
			arr[i].clear();
		}
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &u, &v, &c);
			arr[u].push_back(v);
			if (c == 2)
				arr[v].push_back(u);
		}
		for (int i = 1; i <= n; i++) {
			if (dfs_num[i] == -1)
				dfs(i);
		}
		printf("%d\n", (numSCC == 1) ? 1 : 0);
	}

}
