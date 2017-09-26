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
int n, x, y, m, vis[101];
vi arr[101], v;
/*void dfs(int cur) {
 for (int i = 0; i < sz(arr[cur]); i++) {
 if (!vis[arr[cur][i]]) {
 vis[arr[cur][i]] = 1;
 dfs(arr[cur][i]);
 }
 }
 }*/
void bfs(int cur) {
	queue<int> q;
	q.push(cur);
	while (q.size()) {
		int xx = q.front();
		q.pop();
		for (int i = 0; i < sz(arr[xx]); i++) {
			if (!vis[arr[xx][i]]) {
				vis[arr[xx][i]] = 1;
				q.push(arr[xx][i]);
			}
		}
	}
}
void clr() {
	for (int i = 1; i <= n; i++) {
		arr[i].clear();
	}
}
int main() {
	file();
	while (scanf("%d", &n) && n) {
		while (scanf("%d", &x) && x) {
			while (scanf("%d", &y) && y) {
				arr[x].push_back(y);
			}
		}
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			scanf("%d", &x);
			mem(vis, 0);
			v.clear();
			//dfs(x);
			bfs(x);
			for (int i = 1; i <= n; i++) {
				if (!vis[i])
					v.push_back(i);
			}
			printf("%d", sz(v));
			for (int i = 0; i < sz(v); i++) {
				printf(" %d", v[i]);
			}
			printf("\n");
		}
		clr();
	}
	return 0;
}

