#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define PI 3.1415926535897932384626433832795
#define ll long long
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define mem(a,b) memset(a,b,sizeof a)
#define oo 1e8
#define sz(v) ((int)((v).size()))
#define minn(a, b, c) min(min(a, b), c)
#define maxx(a, b, c) max(max(a, b), c)
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int di[] = { 1, -1, 0, 0 };
int dj[] = { 0, 0, 1, -1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	// online submission
	//freopen("interesting.in", "r", stdin);
#endif
}
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\/\/\/\/\/\/
int n, m;
char c[101][101];
//vector<pair<int, char>> arr[101];
int vis[101][101], flag = 0;
int valid(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}
void bfs(int x, int y, char clr) {
	queue<pair<pair<int, int>, char>> q;
	q.push(mp(mp(x, y), clr));
	while (sz(q)) {
		int xx = q.front().first.first;
		int yy = q.front().first.second;
		char cc = q.front().second;
		q.pop();
		if (cc != clr)
			return;
		if (vis[xx][yy]) {
			flag = 1;
			return;
		}
		vis[xx][yy] = 1;
		for (int i = 0; i < 4; i++) {
			int newx = xx + di[i];
			int newy = yy + dj[i];
			char newc = c[newx][newy];
			if (valid(xx, yy) && !vis[newx][newy] && c[xx][yy] == newc) {
				q.push(mp(mp(newx, newy), c[newx][newy]));
			}
		}
	}
}
int main() {
	file();
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!vis[i][j])
				bfs(i, j, c[i][j]);
		}
	}
	printf(flag ? "Yes" : "No");
}

