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
vi vs, topo;
int n, m, t, u, v, res;

void dfs(int u) {
	vs[u] = 1;
	for (auto v : arr[u])
		if (!vs[v])
			dfs(v);
	if (!res)
		topo.pb(u);
}

int main() {
	file();
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		vs.assign(n + 1, 0), topo.clear(), arr.assign(n + 1, vi());
		for (int i = 0; i < m and scanf("%d%d", &u, &v); ++i)
			arr[u].pb(v);

		res = 0;
		for (int i = 1; i <= n; i++)
			if (!vs[i])
				dfs(i);
		vs.assign(n + 1, 0), reverse(all(topo));
		for (auto vv : topo)
			if (!vs[vv])
				res++, dfs(vv);
		printf("%d\n", res);
	}
	return 0;
}
