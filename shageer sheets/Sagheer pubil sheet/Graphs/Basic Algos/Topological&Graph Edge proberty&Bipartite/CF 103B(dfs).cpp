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
int n, m, u, v, vis[101], cnt;
vi arr[101];
void dfs(int cur) {
	cnt++;
	vis[cur] = 1;
	for (int i = 0; i < sz(arr[cur]); i++) {
		if (!vis[arr[cur][i]])
			dfs(arr[cur][i]);
	}
}
int main() {
	file();
	//3a4an yb2a fe cycle y2ba 3dd el edges==nodes
	//w3a4an a4of kol el trees yb2a 3dd el edges= nodes-1
	//yb2a ana lazem el edges=nodes fe kol el tree 3a4an yb2a fe cycle wa7da wl ba2e trees
	scanf("%d%d", &n, &m);
	if (n == m) {
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &u, &v);
			arr[u].push_back(v);
			arr[v].push_back(u);
		}
		dfs(1);
		if (cnt == n)
			printf("FHTAGN!");
		else
			puts("NO");
	} else
		puts("NO");

}
