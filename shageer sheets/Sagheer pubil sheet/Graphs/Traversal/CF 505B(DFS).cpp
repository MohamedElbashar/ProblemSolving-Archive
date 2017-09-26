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
int n, m, u, v, c, vis[101], q;
vpi arr[101];
int col;
int ans[101];
void dfs(int x, int y, int clr) {
	if (vis[x])
		return;
	vis[x] = 1;
	if (x == y) {
		ans[clr] = 1;
		return;
	}
	for (int i = 0; i < sz(arr[x]); i++) {
		if (arr[x][i].second == clr)
			dfs(arr[x][i].first, y, clr);
	}
}
int main() {
	file();
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &u, &v, &c);
		arr[u].pb( { v, c });
		arr[v].pb( { u, c });
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		scanf("%d%d", &u, &v);
		for (int i = 0; i < sz(arr[u]); i++) {
			dfs(u, v, arr[u][i].second);
			mem(vis, 0);
		}
		int cnt = 0;
		for (int i = 0; i <= m; i++) {
			cnt += ans[i];
		}
		printf("%d\n", cnt);
		mem(ans, 0);
	}

}

