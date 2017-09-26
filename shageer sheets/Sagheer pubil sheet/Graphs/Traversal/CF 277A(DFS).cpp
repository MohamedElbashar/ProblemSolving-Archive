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
int n, m, vis[202], x, xx;
vi arr[202];
void dfs(int cur) {
	vis[cur] = 1;
	for (int i = 0; i < sz(arr[cur]); i++) {
		if (!vis[arr[cur][i]])
			dfs(arr[cur][i]);
	}
}
int main() {
	/*3awz a3ml bipartite graph b7es arbot el nas bl language
	 arr[i].push_back(xx + n);
	 arr[xx + n].push_back(i);
	 hena 3a4an a3ml relation among pepole and language
	 5let nos el array el tane y2ole el lo8a de kam wa7ed y2dr yst5dmha
	 wl nos el awl by2ole el person da m3ah kam lo8a
	 */
	file();
	scanf("%d%d", &n, &m);
	int cnt = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		cnt += x;
		for (int j = 0; j < x; j++) {
			scanf("%d", &xx);

			arr[i].push_back(xx + n);
			arr[xx + n].push_back(i);
		}
	}
	if (!cnt)
		printf("%d", n);
	else {
		for (int i = 1; i <= n; i++) {
			if (!vis[i])
				dfs(i), ++ans;
		}
		printf("%d", ans - 1);
	}
}

