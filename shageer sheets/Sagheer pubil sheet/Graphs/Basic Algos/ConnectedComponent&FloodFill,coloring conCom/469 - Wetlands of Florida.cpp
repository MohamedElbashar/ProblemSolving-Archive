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
char arr[101][101];
int vis[101][101];
int ans = 0;
int n, m;
int floodfill(int r, int c) {
	if (r < 0 || r >= n || c < 0 || c >= m || arr[r][c] == 0)
		return 0;
	if (arr[r][c] != 'W' || vis[r][c] != 0)
		return 0;
	vis[r][c] = 1;
	ans++;
	for (int i = 0; i < 8; i++) {
		floodfill(r + dx[i], c + dy[i]);
	}
}
int main() {
	file();
	int t, i, j;
	char str[105];
	scanf("%d ", &t);
	while (t--) {
		mem(arr, 0);
		n = 0, m = 0;
		while (gets(str)) {
			if (m == 0)
				m = strlen(str);
			if (str[0] == '\0')
				break;
			if (str[0] != 'W' && str[0] != 'L') {
				sscanf(str, "%d %d", &i, &j);
				mem(vis, 0);
				ans = 0;
				floodfill(i - 1, j - 1);
				printf("%d\n", ans);
			} else {
				sscanf(str, "%s", arr[n]);
				n++;
			}
		}
		if (t)
			puts("");
	}
	return 0;
}

