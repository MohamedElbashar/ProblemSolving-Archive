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
char c[101][101];
int t, n, h, cnt, vis[101][101];
vpi arr;
int valid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}
void dfs(int x, int y) {
	if (vis[x][y] || c[x][y] == '.')
		return;
	vis[x][y] = 1;
	if (c[x][y] == 'x')
		cnt++;
	for (int j = 0; j < 4; j++) {
		int xx = x + di[j];
		int yy = y + dj[j];
		if (valid(xx, yy)) {
			dfs(xx, yy);
		}
	}
}
int main() {
	file();
	scanf("%d", &t);
	while (t--) {
		mem(vis, 0);
		mem(c, 0);
		arr.clear();
		int ans = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			getchar();
			for (int j = 0; j < n; j++) {
				scanf("%c", &c[i][j]);
				if (c[i][j] == 'x' || c[i][j] == '@')
					arr.pb( { i, j });
			}
		}
		for (int i = 0; i < sz(arr); i++) {
			cnt = 0;
			dfs(arr[i].first, arr[i].second);
			if (cnt)
				ans++;
		}
		printf("Case %d: %d\n", ++h, ans);
	}

}

