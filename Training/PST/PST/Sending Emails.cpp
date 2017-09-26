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

vector<pair<int, int> > arr[50001];
int vis[50001];
int n, m, s, en, cnt;
int clear() {
	for (int i = 0; i < n; i++) {
		arr[i].clear();
	}
	memset(vis, 0, (sizeof vis[0]) * n);
}
int dijkstra(int s, int e) {
	priority_queue<node> q;
	q.push(node(s, 0));
	while (!q.empty()) {
		int cur = q.top().v;
		int cost = q.top().c;
		q.pop();
		if (vis[cur])
			continue;
		if (cur == e) {
			cout << "Case #" << ++cnt << ": " << cost << endl;
			return 0;
		}
		vis[cur] = 1;
		for (int i = 0; i < arr[cur].size(); i++) {
			int to = arr[cur][i].first;
			int c = arr[cur][i].second;
			if (vis[arr[cur][i].first])
				continue;
			q.push(node(to, c + cost));
		}
	}
	cout << "Case #" << ++cnt << ": " << "unreachable";
	return 0;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m >> s >> en;
		for (int i = 0; i < m; i++) {
			int u, v, c;
			cin >> u >> v >> c;
			arr[u].push_back(make_pair(v, c));
			arr[v].push_back(make_pair(u, c));
		}
		dijkstra(s, en);
		clear();
	}

}
