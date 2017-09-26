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
vector<vector<int>> adj, comps, daglist;
vi instack, lowlink, dfn, comp;
stack<int> stk;
int ndfn;
void Bridge(int node, int par) {
	lowlink[node] = dfn[node] = ndfn++, instack[node] = 1;
	stk.push(node);
	for (int i = 0; i < sz(adj[node]); i++) {
		if (dfn[adj[node][i]] == -1) {
			Bridge(adj[node][i], node);
			lowlink[node] = min(lowlink[node], lowlink[adj[node][i]]);
		} else if (instack[adj[node][i]]) {
			lowlink[node] = min(lowlink[node], dfn[node]);
		}
	}
	if (lowlink[node] == dfn[node] && par != -1) {
		printf("Bridge %d   %d\n", par, node);
	}
}
void BridgeAnotherWay(int node, int par) {
	lowlink[node] = dfn[node] = ndfn++, instack[node] = 1;
	stk.push(node);
	for (int i = 0; i < sz(adj[node]); i++) {
		if (dfn[adj[node][i]] == -1) {
			BridgeAnotherWay(adj[node][i], node);
			lowlink[node] = min(lowlink[node], lowlink[adj[node][i]]);

			if (lowlink[adj[node][i]] == dfn[adj[node][i]])
				printf("Bridge %d   %d\n", par, node);

		} else if (instack[adj[node][i]]) {
			lowlink[node] = min(lowlink[node], dfn[node]);
		}
	}
}
int main() {
	file();

}
