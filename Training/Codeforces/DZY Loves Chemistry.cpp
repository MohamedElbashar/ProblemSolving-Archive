#include <bits/stdc++.h>
using namespace std;
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\/\/\/\/\/\/
struct node {
	int u, v, c;
	node(int u, int v, int c) :
			u(u), v(v), c(c) {
	}
	bool operator <(const node &e) const {
		return c > e.c;
	}
};
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define rep( i, n ) for (int i = 0; i < (n); i++)
#define scan(n) scanf("%d",&n)
#define scanl(n) scanf("%I64d",&n)
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
#define oo 1e8
#define minn(a, b, c) min(min(a, b), c)
#define maxx(a, b, c) max(max(a, b), c)
int di[] = { 0, -1, 0, 1 };
int dj[] = { 0, 1, 1, 1 };
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
int n, m;
vi v[100];
int vis[100];
ll dfs(int ind) {
	vis[ind] = 1;
	ll ans = 1;
	for (int i = 0; i <(int) v[ind].size(); i++) {
		if (vis[v[ind][i]] == -1)
			ans *= (2 * dfs(v[ind][i]));
	}
	return ans;
}
int main() {
	file();
	mem(vis, -1);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	ll res = 1;
	for (int i = 1; i <= n; i++) {
		if (vis[i] == -1)
			res *= dfs(i);
	}
	cout << res;
}
