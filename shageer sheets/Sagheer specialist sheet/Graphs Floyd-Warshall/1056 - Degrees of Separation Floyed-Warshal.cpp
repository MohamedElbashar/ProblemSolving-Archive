#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pi> vpi;
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define mem(a,b) memset(a,b,sizeof a)
#define sz(v) ((int)((v).size()))
#define minn(a, b, c) min(min(a, b), c)
#define maxx(a, b, c) max(max(a, b), c)and
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
	//freopen("sets.in", "r", stdin);
#endif
}
//\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\//\/\/\/\/\/\/\/\/\/\/
int p, r, adj[51][51], c;
int main() {
	file();
	while (scanf("%d%d", &p, &r) && p && r) {
		int cnt = 1;
		for (int i = 1; i <= p; i++) {
			for (int j = 1; j <= p; j++) {
				adj[i][j] = 1e9;
			}
		}
		string u, v;
		map<string, int> name;
		for (int i = 0; i < r; i++) {
			cin >> u >> v;
			if (name.find(u) == name.end()) {
				name[u] = cnt++;
			}
			if (name.find(v) == name.end()) {
				name[v] = cnt++;
			}
			adj[name[u]][name[v]] = adj[name[v]][name[u]] = 1;
		}
		for (int k = 1; k <= p; k++) {
			for (int i = 1; i <= p; i++) {
				for (int j = 1; j <= p; j++) {
					adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
				}
			}
		}
		int mx = 0;
		for (int i = 1; i <= p; i++) {
			for (int j = i + 1; j <= p; j++) {
				mx = max(adj[i][j], mx);
			}
		}
		if (mx == 1e9) {
			printf("Network %d: DISCONNECTED\n", ++c);
		} else
			printf("Network %d: %d\n", ++c, mx);
		if (p)
			puts("");
	}
}
