#include <bits/stdc++.h>
using namespace std;
struct node {
	int v, c, u;
	node(int v, int u, int c) :
			v(v), u(u), c(c) {
	}
	bool operator <(const node &e) const {
		return c > e.c;
	}
};
/**************BASHAR*****************/
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define rep( i, n ) 	for ( int i = 0; i < (n); i++ )
#define scan(n) scanf("%d",&n)
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
#define oo 1e9
#define fir first
#define sec second
int di[] = { 1, -1, 0, 0 };
int dj[] = { 0, 0, 1, -1 };
void file() {
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#else
// online submission
	freopen("interesting.in", "r", stdin);
#endif
}
/**************BASHAR*****************/
int t, n, m, cnt;
int arr[501][501];
priority_queue<node> q;
queue<pair<int, int> > qq;
int valid(int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < m;
}
int dis(int i, int j, int x, int y) {
	return abs(x - i) + abs(y - j);
}

int solve() {
	while (!q.empty()) {
		int i = q.top().v;
		int j = q.top().u;
		int c = q.top().c;
		q.pop();
		for (int z = 0; z < 4; z++) {
			int x = di[z] + i;
			int y = dj[z] + j;
			if (dis(i, j, x, y) <= arr[i][j])
				if (valid(x, y) && !arr[x][y]) {
					{
						arr[x][y] = 1;
						qq.push(make_pair(x, y));
						cnt++;
					}
				}
		}
		while (!qq.empty()) {
			int xx = qq.front().first;
			int yy = qq.front().second;
			qq.pop();
			for (int z = 0; z < 4; z++) {
				int x = di[z] + xx;
				int y = dj[z] + yy;
				if (dis(i, j, x, y) <= arr[i][j])
					if (valid(x, y) && !arr[x][y]) {
						{
							arr[x][y] = 1;
							qq.push(make_pair(x, y));
							cnt++;
						}
					}
			}

		}
	}
	return cnt;
}
int clearr() {
	while (q.size()) {
		q.pop();
	}
	while (qq.size()) {
		qq.pop();
	}
}
int main() {
	file();
	scan(t);
	while (t--) {
		scanf("%d%d", &n, &m);
		mem(arr, 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scan(arr[i][j]);
				if (arr[i][j]) {
					q.push(node(i, j, arr[i][j]));

				}
			}
		}
		int qs = q.size();
		int qq = solve();
		int xx = n * m;
		int yy = xx - (qq + qs);
		cout << yy << endl;
		cnt = 0;
		clearr();
	}
}
