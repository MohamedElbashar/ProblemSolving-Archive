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
int n, arr[9][9], vis[20], rd[35], ld[35], rs, cnt, ans[20];
void backtrack(int c) {
	if (c == 8) {
		cnt = 0;
		for (int i = 0; i < 8; i++) {
			cnt += ans[i];
		}
		rs = max(rs, cnt);
	}
	for (int r = 0; r < 8; r++) {
		if (!vis[r] && !rd[r + c] && !ld[r - c + 7]) {
			vis[r] = rd[r + c] = ld[r - c + 7] = 1;
			ans[r] = arr[r][c];
			backtrack(c + 1);
			vis[r] = rd[r + c] = ld[r - c + 7] = 0;
		}
	}
}
int main() {
	file();
	scanf("%d", &n);
	while (n--) {
		mem(vis,0), mem(rd, 0), mem(ld, 0);
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				scanf("%d", &arr[i][j]);
		backtrack(0);
		printf("%5d\n", rs);
		rs = 0;

	}

}
