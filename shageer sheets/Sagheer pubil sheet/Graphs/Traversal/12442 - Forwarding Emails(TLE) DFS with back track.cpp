#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define PI 3.1415926535897932384626433832795
#define ll long long
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
int n, t, x, y, vis[50001], c, cost[50001];
vi arr[50001];
int dfs(int cur) {
	vis[cur] = 1;
	int ret = 0;
	for (int i = 0; i < sz(arr[cur]); i++) {
		if (!vis[arr[cur][i]]) {
			ret += dfs(arr[cur][i]) + 1;
		}
		vis[arr[cur][i]] = 0;
	}
	return cost[cur] = ret;
}
void clr() {
	for (int i = 1; i <= n; i++) {
		arr[i].clear();
	}

}
int main() {
	file();
	scanf("%d", &t);
	while (t--) {
		mem(cost, -1);
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &x, &y);
			arr[x].push_back(y);
		}
		int res = 0, ans;
		mem(vis, 0);
		for (int i = 1; i <= n; i++) {
			if (cost[i] == -1) {
				dfs(i);
				if (cost[i] > res) {
					ans = i;
					res = cost[i];
				} else if (cost[i] == res) {
					ans = min(ans, i);
					res = cost[i];
				}
			}
		}
		printf("Case %d: %d\n", ++c, ans);
		clr();
	}
}

