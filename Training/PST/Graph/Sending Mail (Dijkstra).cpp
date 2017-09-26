#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
const int m	axN = 20010, maxE = 50010;
vector<ii> adjList[maxN];
int n, m, s, e, vis[maxN];

void clear() {
	for (int i = 0; i < n; i++)
		adjList[i].clear();
	memset(vis, 0, (sizeof vis[0]) * n);
}
void dijkstra() {
	priority_queue<ii> pq;
	pq.push(ii(0, s));
	while (pq.size()) {
		int cur = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (vis[cur])
			continue;
		vis[cur] = 1;
		if (cur == e) {
			cout << cost << endl;
			return;
		}
		for (int i = 0; i < adjList[cur].size(); i++) {
			int to = adjList[cur][i].first;
			int c = adjList[cur][i].second;
			if (vis[to])
				continue;
			pq.push(ii(-cost - c, to));
		}

	}
	cout << "unreachable" << endl;

}
int main() {
	int t;
	cin >> t;
	for (int C = 0; C < t; C++) {
		cin >> n >> m >> s >> e;
		for (int i = 0; i < m; i++) {
			int u, v, c;
			scanf("%d %d %d", &u, &v, &c);
			adjList[u].push_back(ii(v, c));
			adjList[v].push_back(ii(u, c));
		}
		printf("Case #%d: ", C + 1);
		dijkstra();
		clear();
	}
}
