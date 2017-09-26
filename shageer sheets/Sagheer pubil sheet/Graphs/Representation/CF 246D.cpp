#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define PI 3.1415926535897932384626433832795
#define ll long long
#define all(v) v.begin(),v.end()
#define mem(a,b) memset(a,b,sizeof a)
#define oo 1e8
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
int n, m, u, v;
int c[100001];
set<int> arr[100001];
int main() {
	file();
	scanf("%d%d", &n, &m);
	int mx = 0, mn = oo;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
		mx = max(mx, c[i]);
		mn = min(mn, c[i]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &u, &v);
		if (c[u] != c[v]) {
			arr[c[u]].insert(c[v]);
			arr[c[v]].insert(c[u]);
		}
	}
	int res = 0, clr = mn;
	for (int i = 0; i <= mx; i++) {
		if ((int) arr[i].size() > res)
			res = (int) arr[i].size(), clr = i;
		else if (res == (int) arr[i].size() && res != 0) {
			clr = min(clr, i);
		}
	}
	printf("%d", clr);
}
