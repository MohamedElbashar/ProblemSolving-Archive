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
int n, vis[100], u, v;
vi arr[100], topoSort;
void dfs(int cur) {
	vis[cur] = 1;
	for (int i = 0; i < sz(arr[u]); i++) {
		if (!vis[arr[cur][i]]) {
			dfs(arr[cur][i]);
		}
	}
	topoSort.push_back(cur);
}
int main() {
	file();
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &u, &v);
		arr[u].push_back(v);
	}
	for (int i = 1; i < n; i++) {
		if (!vis[i])
			dfs(i);
	}
	//printf TopoSort vector in reversed order
}

