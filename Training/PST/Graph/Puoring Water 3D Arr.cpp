#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
int a, b, c;
int cost[2][2][40010];
int vis[2][2][40010];

queue<ii> q;
void get(int ca, int cb, int &x, int &y, int &z) {
	if (!ca) {
		x = 0;
		y = 1;
		z = cb;
	} else if (ca == a) {
		x = 0;
		y = 0;
		z = cb;
	} else if (!cb) {
		x = 1;
		y = 1;
		z = ca;
	} else { //cb==b
		x = 1;
		y = 0;
		z = ca;
	}
}

void Try(int ca, int cb, int co) {
	int x, y, z;
	get(ca, cb, x, y, z);
	if (!vis[x][y][z]) {
		vis[x][y][z] = 1;
		q.push(ii(ca, cb));
		cost[x][y][z] = co;
	}
}

void solve() {
	memset(vis, 0, sizeof vis);
	while (q.size())
		q.pop();
	cin >> a >> b >> c;
	q.push(ii(0, 0));
	vis[0][1][0] = 1;
	while (q.size()) {
		int ca = q.front().first;
		int cb = q.front().second;
		q.pop();
		int x, y, z;
		get(ca, cb, x, y, z);
		if (ca == c || cb == c) {
			cout << cost[x][y][z] << endl;
			return;
		}
		int co = cost[x][y][z] + 1;
		Try(0, cb, co);
		Try(ca, 0, co);
		Try(a, cb, co);
		Try(ca, b, co);
		Try(ca + min(a - ca, cb), cb - min(a - ca, cb), co);
		Try(ca - min(ca, b - cb), cb + min(ca, b - cb), co);

	}
	cout << "-1\n";
}
int main() {
	int t;
	cin >> t;
	while (t--)
		solve();

}
