#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define ll long long
#define mem(a,b) memset(a,b,sizeof a)
#define oo 1e8
#define minn(a, b, c) min(min(a, b), c)
#define maxx(a, b, c) max(max(a, b), c)
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int di[] = { 0, -1, 0, 1 };
int dj[] = { 0, 1, 1, 1 };
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
char map[100][100];
void dfs(int x, int y) {
	if (map[x][y] == 'X' || map[x][y] == '#')
		return;
	map[x][y] = '#';
	dfs(x + 1, y);
	dfs(x - 1, y);
	dfs(x, y + 1);
	dfs(x, y - 1);
}
int main() {
	int t, i, j;
	scanf("%d ", &t);
	while (t--) {
		int n = 0;
		while (gets(map[n])) {
			if (map[n][0] == '_')
				break;
			n++;
		}
		for (i = 0; i < n; i++) {
			for (j = 0; map[i][j]; j++) {
				if (map[i][j] == '*')
					dfs(i, j);
			}
		}
		for (i = 0; i <= n; i++)
			puts(map[i]);
	}
	return 0;
}
