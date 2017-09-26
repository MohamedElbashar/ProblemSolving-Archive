#include <bits/stdc++.h>
using namespace std;
int t, n, cnttt, cnt3, xx, yy;
char arr[501][501];
int di[] = { 1, -1, 0, 0 };
int dj[] = { 0, 0, 1, -1 };
int valid(int i, int j) {
	return i >= 0 && i < 2 && j >= 0 && j < n && arr[i][j] == '#';
}
int solve(int x, int y) {
	int vis[501][501] = { 0 };
	queue<pair<int, int> > qq;
	qq.push(make_pair(x, y));
	vis[x][y] = 1;
	int i, j;
	while (!qq.empty()) {
		i = qq.front().first, j = qq.front().second;
		qq.pop();
		vis[i][j] = 1;
		for (int z = 0; z < 4; z++) {
			int id = i + di[z];
			int jd = j + dj[z];
			if (valid(id, jd) && !vis[id][jd]) {
				qq.push(make_pair(id, jd));
			}
		}
	}
	xx = i, yy = j;
	return 0;
}
int BFS(int x, int y, int cntt) {
	int vis[501][501] = { 0 };
	cnt3 = 0;
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	vis[x][y] = 1;
	while (!q.empty()) {
		int i = q.front().first, j = q.front().second;
		q.pop();
		cnt3++;
		for (int z = 0; z < 4; z++) {
			int id = i + di[z];
			int jd = j + dj[z];
			if (valid(id, jd) && !vis[id][jd]) {
				q.push(make_pair(id, jd));
				vis[id][jd] = 1;
			}
		}
	}
	if (cnt3 == cntt)
		return true;
	else
		return false;
}
int main() {
	freopen("out.txt", "w", stdout);
	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < 2; i++) {
			scanf("%s", arr[i]);
		}
		int x, y, flag = 0, cnttt = 0;
		for (int i = 0; i < 2; i++) {
			if (flag) {
				break;
			}
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == '#') {
					x = i;
					y = j;
					flag = 1;
					break;
				}

			}
		}
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == '#') {
					cnttt++;
				}
			}
		}
		solve(x, y);
		if (!BFS(xx, yy, cnttt)) {
			printf("%s", "no\n");
		} else {
			printf("%s", "yes\n");

		}
	}

}
