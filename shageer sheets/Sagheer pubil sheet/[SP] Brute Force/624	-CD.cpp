#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define PI 3.1415926535897932384626433832795
#define ll long long
#define mem(a,b) memset(a,b,sizeof a)
#define oo 1e8
#define minn(a, b, c) min(min(a, b), c)
#define all(v) v.begin(), v.end()
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
int n, m, arr[21], vis[21], cur[21], res[21], ans, cnt;
void backtrack(int c) {
	if (c == n) {
		ans = 0;
		for (int i = 0; i < n; i++)
			if (vis[i])
				ans += arr[i];
		if (ans <= m)
			if (cnt < ans) {
				cnt = max(cnt, ans);
				for (int i = 0; i < n; i++)
					cur[i] = vis[i];
			}

		return;
	}

	vis[c] = 1;
	backtrack(c + 1);
	vis[c] = 0;
	backtrack(c + 1);
}
int main() {
	file();
	while (scanf("%d%d", &m, &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		mem(vis, 0);
		ans = 0;
		cnt = 0;
		backtrack(0);
		for (int i = 0; i < n; i++) {
			if (cur[i])
				printf("%d ", arr[i]);
		}
		printf("sum:%d\n", cnt);
	}
}
