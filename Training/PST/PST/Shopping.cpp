#include <bits/stdc++.h>
using namespace std;
struct node {
	int i, j, w;
	node(int i, int j, int w) :
			i(i), j(j), w(w) {
	}
	bool operator <(const node &e) const {
		return w > e.w;
	}
};
char arr[26][26];
int vis[26][26], cost[26][26];
int di[] = { 1, -1, 0, 0 };
int dj[] = { 0, 0, 1, -1 };
int n, m, si, sj, ei, ej;
bool valid(int i, int j) {
	return i >= 0 && i < m && j >= 0 && j < n;
}
void solve() {
	priority_queue<node> q;
	q.push(node(si, sj, 0));
	vis[si][sj] = 1;
	cost[si][sj] = 0;
	while (!q.empty()) {
		int i = q.top().i;
		int j = q.top().j;
		int cst = q.top().w;
		q.pop();
		for (int z = 0; z < 4; z++) {
			int ti = i + di[z];
			int tj = j + dj[z];
			if (!vis[ti][tj] && valid(ti, tj) && arr[ti][tj] != 'X') {
				if (arr[ti][tj] == 'D') {
					cout << cst << endl;
					return;
				}
				cost[ti][tj] = min(cost[ti][tj], cst + (arr[ti][tj] - '0'));
				vis[ti][tj] = 1;
				q.push(node(ti, tj, cost[ti][tj]));
			}
		}
	}
}
int main() {

	while (cin >> n >> m && n && m) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
				cost[i][j] = INT_MAX;
				if (arr[i][j] == 'S') {
					si = i;
					sj = j;
				}
			}
		}
		solve();
		memset(vis,0,sizeof vis);
	}

}
