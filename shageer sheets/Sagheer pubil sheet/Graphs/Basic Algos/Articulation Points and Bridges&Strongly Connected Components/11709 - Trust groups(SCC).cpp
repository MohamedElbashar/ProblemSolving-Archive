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
vi arr[1001], s;
map<string, int> mmp;
string fir, sec;
int n, m, uu, vv, dfs_num[1001], dfs_low[1001], vis[1001], numcounter, NumScc;
void scc(int u) {
	s.push_back(u);
	dfs_low[u] = dfs_num[u] = numcounter++, vis[u] = 1;
	for (int i = 0; i < sz(arr[u]); i++) {
		int v = arr[u][i];
		if (dfs_num[v] == -1)
			scc(v);
		if (vis[v])
			dfs_num[u] = min(dfs_num[u], dfs_num[v]);
	}
	if (dfs_low[u] == dfs_num[u]) {
		while (1) {
			int cur = s.back();
			s.pop_back();
			vis[cur] = 0;
			if (u == cur)
				break;
		}
		NumScc++;

	}
}
int main() {
	file();
	while (scanf("%d%d", &n, &m) && n) {
		for (int i = 0; i <= n + 1; i++) {
			arr[i].clear();
		}
		mmp.clear(), s.clear();
		mem(dfs_num,-1), mem(dfs_low, 0), mem(vis, 0), numcounter = 0, NumScc =
				0;
		for (int i = 0; i < n; i++) {
			cin >> fir >> sec;
			mmp[fir + sec] = i;
		}
		for (int i = 0; i < m; i++) {
			cin >> fir >> sec;
			uu = mmp[fir + sec];
			cin >> fir >> sec;
			vv = mmp[fir + sec];
			arr[uu].push_back(vv);
		}
		for (int i = 0; i < n; i++) {
			if (dfs_num[i] == -1) {
				scc(i);
			}
		}
		printf("%d\n", NumScc);
	}

}
