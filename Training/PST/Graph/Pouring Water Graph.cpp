#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
int a, b, c;
int cost[105][105];
int vis[105][105];

queue<ii> q;

void Try(int a, int b, int co) {
	if (!vis[a][b]) {
		vis[a][b] = 1;
		q.push(ii(a, b));
		cost[a][b] = co;
	}
}

void solve() {
	memset(vis, 0, sizeof vis);
	while (q.size())
		q.pop();
	cin >> a >> b >> c;
	q.push(ii(0, 0));
	vis[0][0] = 1;
	while (q.size()) {
		int ca = q.front().first;
		int cb = q.front().second;
		q.pop();
		if (ca == c || cb == c) {
			cout << cost[ca][cb] << endl;
			return;
		}
		int co = cost[ca][cb] + 1;
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

}
