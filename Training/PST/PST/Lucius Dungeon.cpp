#include <bits/stdc++.h>
using namespace std;
typedef pair<pair<int, int>, int> ii;
int arr[101][101];
int vis[101][101];
int depth[101][101];
int n, m;
int di[4] = { 1, -1, 0, 0 };
int dj[4] = { 0, 0, 1, -1 };
struct node {
	int x, y, cost;
	node(int x, int y, int cost) :
			x(x), y(y), cost(cost) {
	}
	bool operator <(const node &e) const {
		return cost < e.cost;
	}
};
bool valid(int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < m;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j];
			}
		}
		int ei, ej, her;
		cin >> ei >> ej >> her;
		priority_queue<node> q;
		depth[0][0] = her - arr[0][0];
		vis[0][0] = 1;
		q.push(node(0, 0, depth[0][0]));
		while (!q.empty()) {
			int i = q.top().x;
			int j = q.top().y;
			q.pop();
			if (i == ei - 1 && j == ej - 1 && depth[i][j] >= 0) {
				cout << "YES" << endl;
				cout << depth[i][j] << endl;
				break;
			}
			if (depth[i][j] < 0 && i == ei - 1 && j == ej - 1) {
				cout << "NO" << endl;
				break;
			}
			for (int k = 0; k < 4; k++) {
				int ti = i + di[k];
				int tj = j + dj[k];
				if (!vis[ti][tj] && valid(ti, tj)) {
					depth[ti][tj] = depth[i][j] - arr[ti][tj];
					vis[ti][tj] = 1;
					q.push(node(ti, tj, depth[ti][tj]));
				}
			}
		}
		memset(vis, 0, sizeof vis);
	}
}
