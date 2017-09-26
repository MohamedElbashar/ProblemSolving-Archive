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
char g[26][26], p[26], u[26];
char cflag, tot;
void dfs(int nd, int p) {
	u[nd] = 1;
	if (cflag)
		return;
	int i;
	tot++;
	for (i = 0; i < 26; i++) {
		if (g[nd][i] && u[i] && i != p)
			cflag = 1;
		if (g[nd][i] && u[i] == 0)
			dfs(i, nd);
	}
}
int main() {
	int t, i;
	char cmd[128];
	scanf("%d", &t);
	while (getchar() != '\n')
		;
	while (t--) {
		memset(g, 0, sizeof(g));
		memset(p, 0, sizeof(p));
		memset(u, 0, sizeof(u));
		while (gets(cmd) && cmd[0] != '*') {
			g[cmd[1] - 'A'][cmd[3] - 'A'] = 1;
			g[cmd[3] - 'A'][cmd[1] - 'A'] = 1;
		}
		memset(cmd, 0, sizeof(cmd));
		gets(cmd);
		for (i = 0; cmd[i]; i += 2)
			p[cmd[i] - 'A'] = 1;
		int tree = 0, acorn = 0;
		for (i = 0; i < 26; i++) {
			if (p[i] && u[i] == 0) {
				cflag = 0, tot = 0;
				dfs(i, -1);
				if (cflag == 0 && tot > 1)
					tree++;
				if (tot == 1)
					acorn++;
			}
		}
		printf("There are %d tree(s) and %d acorn(s).\n", tree, acorn);
	}
	return 0;
}

