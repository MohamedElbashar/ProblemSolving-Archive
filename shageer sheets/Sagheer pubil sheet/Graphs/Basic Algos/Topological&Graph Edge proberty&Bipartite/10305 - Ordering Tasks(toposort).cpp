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
int n, m, vis[101], u, v;
vi arr[101], ans;
void dfs(int cur) {
	vis[cur] = 1;
	for (int i = 0; i < sz(arr[cur]); i++) {
		if (!vis[arr[cur][i]])
			dfs(arr[cur][i]);
	}
	ans.pb(cur);
}
int main() {
	file();
	while (scanf("%d%d", &n, &m) && n) {
		mem(vis, 0), ans.clear();
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &u, &v);
			arr[u].push_back(v);
		}
		for (int i = 1; i <= n; i++)
			if (!vis[i])
				dfs(i);
		reverse(all(ans));
		printf("%d", ans[0]);
		for (int i = 1; i < sz(ans); i++) {
			printf(" %d", ans[i]);
		}
		printf("\n");
		for (int i = 0; i < n + 1; i++)
			arr[i].clear();
	}

}

