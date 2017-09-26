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
int n, m, k, x, y;
char arr[11][11][11];
int dz[] = { 1, -1 };
int ans = 0;
int valid(int z, int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m && arr[z][x][y] == '.';
}
void dfs(int z, int x, int y) {
	if (!valid(z, x, y))
		return;
	arr[z][x][y] = '#', ans++;
	dfs(z + 1, x, y), dfs(z - 1, x, y), dfs(z, x + 1, y), dfs(z, x - 1, y), dfs(
			z, x, y + 1), dfs(z, x, y - 1);

}
int main() {
	file();
	scanf("%d%d%d", &k, &n, &m);
	getchar();
	for (int i = 0; i < k; i++) {
		getchar();
		for (int j = 0; j < n; j++) {
			for (int l = 0; l < m; l++) {
				cin >> arr[i][j][l];

			}
		}
	}
	getchar();
	scanf("%d%d", &x, &y);
	x--, y--;
	dfs(0, x, y);
	printf("%d", ans);
}

