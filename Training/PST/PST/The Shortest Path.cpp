#include <bits/stdc++.h>
using namespace std;
struct node {
	int v, c;
	node(int v, int c) :
			v(v), c(c) {
	}
	bool operator <(const node &e) const {
		return c > e.c;
	}
};
vector<pair<int, int> > arr[10001];
int vis[10001];
string s;
map<string, int> str;
int n, m;
void solve(int v, int h) {
	priority_queue<node> q;
	q.push(node(v, 0));
	while (!q.empty()) {
		int cur = q.top().v;
		int cost = q.top().c;
		q.pop();
		if (vis[cur])
			continue;
		vis[cur] = 1;
		if (cur == h) {
			printf("%d\n", cost);
			return;
		}
		vis[cur] = 1;
		for (int i = 0; i < arr[cur].size(); i++) {
			int to = arr[cur][i].first;
			int w = arr[cur][i].second;
			if (vis[to]) {
				continue;
			}
			q.push(node(to, cost + w));
		}
	}
}
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		string s;
		for (int i = 0; i < n; i++) {
			cin >> s;
			str[s] = i + 1;
			scanf("%d", &m);
			for (int j = 1; j <= m; j++) {
				int y, cost;
				scanf("%d%d", &y, &cost);
				arr[i + 1].push_back(make_pair(y, cost));
			}
		}
		int t;
		scanf("%d", &t);
		for (int i = 0; i < t; i++) {
			string xx, yy;
			cin >> xx >> yy;
			int sr = str[xx];
			int des = str[yy];
			solve(sr, des);
			memset(vis, 0, sizeof vis);
		}
	}
}
