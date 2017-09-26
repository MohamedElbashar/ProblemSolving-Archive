#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define ll long long
#define mem(a,b) memset(a,b,sizeof a)
#define oo 1e8
#define minn(a, b, c) min(min(a, b), c)
#define maxx(a, b, c) max(max(a, b), c)
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
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
int n, en, cndown, m, u, v, c, cnt;
int vis[101];
struct node {
	int v, c;
	node(int v, int c) :
			v(v), c(c) {
	}
	bool operator <(const node &e) const {
		return c > e.c;
	}
};

vpi arr[101];

int dij(int x, int end) {
	priority_queue<node> q;
	q.push(node(x, 0));
	vis[x] = 1;
	while (!q.empty()) {
		int ii = q.top().v;
		int cc = q.top().c;
		q.pop();
		if (ii == en) {
			return cc;
		}
		for (int i = 0; i < arr[ii].size(); i++) {
			int xx = arr[ii][i].first;
			int w = arr[ii][i].second;
			if (vis[arr[ii][i].first] == -1) {
				q.push(node(xx, w + cc));
				vis[xx] = 1;
			}
		}
	}
}
int main() {
	file();
	scanf("%d%d%d%d", &n, &en, &cndown, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &u, &v, &c);
		arr[u].push_back(make_pair(v, c));
	}
	for (int i = 1; i <= n; i++) {
		mem(vis, -1);
		if (dij(i, en) <= cndown) {
			cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}

