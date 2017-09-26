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
vi arr[100];
int n, m, vis[100], u, v, numComp, parent[100];
void graphcheck(int u) {
	vis[u] = 2;
	for (int i = 0; i < sz(arr[u]); i++) {
		if (!vis[arr[u][i]]) {  // Tree Edge, EXPLORED->UNVISITED
			parent[arr[u][i]] = u;  // parent of this children is me
			graphcheck(arr[u][i]);
		} else if (vis[arr[u][i]] == 2) {  // EXPLORED->EXPLORED
			if (arr[u][i] == parent[u]) {  // to differentiate these two cases
				printf(" Two ways (%d, %d)-(%d, %d)\n", u, arr[u][i], arr[u][i],
						u);
			} else { // the most frequent application: check if the graph is cyclic
				printf(" Back Edge (%d, %d) (Cycle)\n", u, arr[u][i]);
			}
		} else if (vis[arr[u][i]]) { // EXPLORED->VISITED
			printf(" Forward/Cross Edge (%d, %d)\n", u, arr[u][i]);
		}
	}
	vis[u] = 1; // after recursion, color u as VISITED (DONE)

}
int main() {
	file();
	mem(vis, 0);
	mem(parent, 0);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &u, &v);
		arr[u].pb(v);
	}
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			printf("Component %d:\n", ++numComp), graphcheck(i);
		}
	}
}

