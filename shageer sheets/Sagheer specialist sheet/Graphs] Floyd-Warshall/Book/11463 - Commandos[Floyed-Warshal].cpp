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
#define maxx(a, b, c) max(max(a, b), c)and
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
int t, n, m, u, v, adj[101][101], en, st, c;
int main() {
	file();
	scanf("%d", &t);
	while (t--) {
		mem(adj, 5);
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
			adj[i][i] = 0;
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &u, &v);
			adj[u][v] = 1, adj[v][u] = 1;
		}
		scanf("%d%d", &st, &en);
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans = max(ans, adj[st][i] + adj[i][en]);
		}
		printf("Case %d: %d\n", ++c, ans);
	}
}
