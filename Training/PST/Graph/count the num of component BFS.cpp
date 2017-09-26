#include <bits/stdc++.h>
using namespace std;
vector<int> arr[100];
int depth[100];
int m, n, cnt, vis[100];
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		arr[u].push_back(v);
		arr[v].push_back(u);
	}
	queue<int> q;
	q.push(1);
	vis[1] = 1;
	while (q.size()) {
		int cur = q.front();
		q.pop();
		cnt++;
		for (int i = 0; i < arr[cur].size(); i++) {
			int to = arr[cur][i];
			if (vis[to])
				continue;
			vis[to] = 1;
			q.push(to);
		}
	}
	cout << cnt;

}
