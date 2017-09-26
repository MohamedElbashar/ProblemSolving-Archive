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
int vis[101][101], flag = 0;
int valid(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}
void dfs(int x, int y, int fx, int fy, char clr) {
	if (clr != c[x][y])
		return;
	if (vis[x][y]) {
		flag = 1;
		return;
	}
	vis[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int xx = x + di[i];
		int yy = y + dj[i];
		if (xx == fx && yy == fy)
			continue;
		if (valid(xx, yy))
			dfs(xx, yy, x, y, clr);
	}
}
int main() {
	file();
	//a3ml 2 var a4of a5zn feha el 7arka ele 2able
	//ana gay mnen y3ene
	scanf("%d%d", &n, &m);
	mem(vis, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!vis[i][j])
				dfs(i, j, -1, -1, c[i][j]);
		}
	}
	printf(flag ? "Yes" : "No");
}

