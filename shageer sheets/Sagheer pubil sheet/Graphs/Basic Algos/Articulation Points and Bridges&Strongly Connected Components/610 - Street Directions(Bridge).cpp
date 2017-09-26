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
vi arr[1001];
vpi br;
int n, m, from, to, dfsNumberCounter, cnt, dfs_low[1001], dfs_num[1001],
		dfs_parent[1001];
void Bridge(int u) {
	dfs_num[u] = dfs_low[u] = dfsNumberCounter++;
	for (int i = 0; i < sz(arr[u]); i++) {
		int v = arr[u][i];

		if (dfs_num[v] == -1) {
			br.push_back( { u, v });
			dfs_parent[v] = u;
			Bridge(v);
			if (dfs_low[v] > dfs_num[u]) {
				br.push_back(make_pair(v, u));
			}
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		} else if (v != dfs_parent[u]) {
			br.push_back( { u, v });
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
			auto idx = lower_bound(all(arr[v]), u);
			if (arr[v][(int) (idx - arr[v].begin())] == u) {
				arr[v].erase(idx);
			}
		}
	}
}
int main() {
	file();
	while (scanf("%d%d", &n, &m) && n) {
		dfsNumberCounter = 0, mem(dfs_num, -1), mem(dfs_parent, 0), mem(dfs_low,
				0), br.clear();
		for (int i = 0; i <= n + 1; i++)
			arr[i].clear();
		printf("%d\n\n", ++cnt);
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &from, &to);
			arr[from].push_back(to);
			arr[to].push_back(from);
		}
		for (int i = 1; i <= n; i++)
			sort(all(arr[i]));
		for (int i = 1; i <= n; i++) {
			if (dfs_num[i] == -1)
				Bridge(i);
		}
		sort(all(br));
		for (int i = 0; i < sz(br); i++) {
			printf("%d %d\n", br[i].first, br[i].second);
		}
		printf("#\n");
	}
}
