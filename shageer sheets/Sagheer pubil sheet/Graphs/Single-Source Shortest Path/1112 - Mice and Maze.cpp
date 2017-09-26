#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pi> vpi;
#define PI 3.1415926535897932384626433832795
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define mem(a,b) memset(a,b,sizeof a)
#define oo LLONG_MAX
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
#define EPS 1e-4
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\/\/\/\/\/\/\/
vpi arr[101];
int t, n, m, e, tc, uu, vv, c, dist[101];
void dijkstra(int st) {
	priority_queue<pi> q;
	q.push( { 0, st });
	while (!q.empty()) {
		pi cur = q.top();
		int u = cur.second;
		q.pop();
		if (u == e)
			return;
		for (int i = 0; i < sz(arr[u]); i++) {
			pi v = arr[u][i];
			if (dist[u] + v.first < dist[v.second]) {
				dist[v.second] = dist[u] + v.first;
				q.push( { -dist[v.second], v.second });
			}
		}
	}
}
int vis[101];
/*int anotherway(int x, int end) {
	priority_queue<pi> q;
	q.push( { x, 0 });
	vis[x] = 1;
	while (!q.empty()) {
		int ii = q.top().first;
		int cc = -q.top().second;
		q.pop();
		if (ii == e) {
			return cc;
		}
		for (int i = 0; i < arr[ii].size(); i++) {
			int xx = arr[ii][i].first;
			int w = arr[ii][i].second;
			if (vis[arr[ii][i].first] == -1) {
				q.push({xx, -(w + cc)});
				vis[xx] = 1;
			}
		}
	}
}*/
void clr() {
	for (int i = 0; i <= n + 1; i++)
		arr[i].clear();
}
int main() {
	file();
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d%d%d", &n, &e, &t, &m);

		int cnt = 0;
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &uu, &vv, &c);
			arr[uu].push_back( { c, vv });
		}
		for (int i = 1; i <= n; i++) {
			fill_n(dist + 1, n, INT_MAX);
			dist[i] = 0;
			dijkstra(i);
			if (dist[e] <= t)
				cnt++;
		}
		printf("%d\n", cnt);
		if (tc)
			printf("\n");

		clr();
	}
}
