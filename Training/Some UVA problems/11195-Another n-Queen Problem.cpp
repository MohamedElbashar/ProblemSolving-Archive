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
char arr[16][16];
int rw[32], ld[32], rd[32], cnt = 0, n, ca;
void backtrack(int c) {
	if (c == n) {
		cnt++;
		return;
	}
	for (int r = 0; r < n; r++) {
		if (arr[r][c] != '*' && !rw[r] && !rd[r + c] && !ld[r - c + n - 1]) {
			rw[r] = ld[r - c + n - 1] = rd[r + c] = 1;
			backtrack(c + 1);
			rw[r] = ld[r - c + n - 1] = rd[r + c] = 0;
		}
	}
}
int main() {
	file();
	while (scanf("%d", &n) && n) {
		for (int i = 0; i < n; i++) {
			scanf("%s", &arr[i]);
		}
		mem(rw, 0), mem(rd, 0), mem(ld, 0);
		backtrack(0);
		printf("Case %d: %d\n", ++ca, cnt);
		cnt = 0;
	}

}

