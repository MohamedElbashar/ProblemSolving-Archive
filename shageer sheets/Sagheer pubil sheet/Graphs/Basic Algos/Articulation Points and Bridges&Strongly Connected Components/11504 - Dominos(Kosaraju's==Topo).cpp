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
vector<vi> arr;
vi vis, topo, dfs_low, dfs_num, s;
int n, m, t, uu, vv, res, num;

void dfs(int u) {
	vis[u] = 1;
	s.push_back(u);
	dfs_low[u] = dfs_num[u] = num++;
	for (int i = 0; i < sz(arr[u]); i++) {
		int v = arr[u][i];
		if (dfs_num[v] == -1) {
			dfs(v);
		}
		if (vis[v])
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}
	if (dfs_low[u] == dfs_num[u]) {
		while (1) {
			int cur = s.back();
			s.pop_back();
			vis[cur] = 0;
			if (u == cur)
				break;
		}
		res++;
	}

}

int main() {
	file();
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		vis.assign(n + 1, 0), topo.clear(), arr.assign(n + 1, vi()), dfs_low.assign(
				n + 1, 0), dfs_num.assign(n + 1, -1);
		num = 0;
		for (int i = 0; i < m and scanf("%d%d", &uu, &vv); ++i)
			arr[uu].pb(vv);

		res = 0;
		for (int i = 1; i <= n; i++)
			if (!vis[i])
				dfs(i);
		vis.assign(n + 1, 0), reverse(all(topo));
		for (auto vv : topo)
			if (!vis[vv])
				dfs(vv);
		printf("%d\n", res);
	}
	return 0;
}
