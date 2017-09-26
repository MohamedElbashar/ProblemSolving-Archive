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
int r, c, n, m, t, w, arr[101][101], cnt, u, v, newx, newy;
vi dr, dc, o, e;
int valid(int x, int y) {
	return x >= 0 && y >= 0 && x < r && y < c;
}

void dfs(int x, int y) {
	if (arr[x][y])
		return;
	arr[x][y] = 1;
	set<pi> s;
	for (int i = 0; i < 8; i++) {
		newx = x + dr[i], newy = dc[i] + y;
		if (valid(newx, newy) && arr[newx][newy] != -1) {
			s.insert( { newx, newy });
			dfs(newx, newy);
		}
	}
	if (sz(s) & 1)
		o.pb(1);
	else
		e.pb(1);
	return;
}
void clr() {
	o.clear();
	e.clear();
	dr.clear();
	dc.clear();
}
int main() {
	file();
	scanf("%d", &t);
	while (t--) {
		mem(arr, 0);
		scanf("%d%d%d%d", &r, &c, &n, &m);
		dr.pb(-m), dr.pb(-m), dr.pb(m), dr.pb(m), dr.pb(-n), dr.pb(n), dr.pb(
				-n), dr.pb(n), dc.pb(n), dc.pb(-n), dc.pb(n), dc.pb(-n), dc.pb(
				m), dc.pb(m), dc.pb(-m), dc.pb(-m);
		scanf("%d", &w);
		for (int i = 0; i < w; i++) {
			scanf("%d%d", &u, &v);
			arr[u][v] = -1;
		}
		dfs(0, 0);
		printf("Case %d: %d %d\n", ++cnt, sz(e), sz(o));
		clr();
	}

}

