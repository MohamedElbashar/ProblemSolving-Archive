#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
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
int n, m, dfs_num[101], dfs_low[101], dfs_parent[101], dfsroot, rootchild,
		dfsNumC, cnt;
vi arr[101], artic;
set<string> s;
string str, st;
vector<string> loc;
map<string, int> mq;
void Artic(int u) {
	dfs_low[u] = dfs_num[u] = dfsNumC++;
	for (int i = 0; i < sz(arr[u]); i++) {
		int v = arr[u][i];
		if (dfs_num[v] == -1) {
			dfs_parent[v] = u;
			if (u == dfsroot)
				rootchild++;
			Artic(v);
			if (u != dfsroot && dfs_low[v] >= dfs_num[u]) {
				artic.push_back(u);
			}
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		} else if (v != dfs_parent[u]) {
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}
	}
}
int main() {
	file();
	while (scanf("%d", &n) && n) {
		if (cnt)
			printf("\n");
		for (int i = 0; i <= n + 1; i++)
			arr[i].clear();
		mq.clear(), artic.clear(), loc.clear(), s.clear();
		mem(dfs_num,-1), mem(dfs_low, 0), mem(dfs_parent, 0), dfsNumC = 0;
		for (int i = 0; i < n; i++) {
			cin >> str;
			mq[str] = i;
			loc.push_back(str);
		}
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			cin >> str >> st;
			arr[mq[str]].push_back(mq[st]);
			arr[mq[st]].push_back(mq[str]);
		}
		for (int i = 0; i <= n; i++) {
			if (dfs_num[i] == -1) {
				dfsroot = i, rootchild = 0, Artic(i);
				if (rootchild > 1)
					artic.push_back(dfsroot);
			}
		}
		for (int i = 0; i < sz(artic); i++) {
			s.insert(loc[artic[i]]);
		}
		printf("City map #%d: %d camera(s) found\n", ++cnt, sz(s));
		while (sz(s)) {
			string cur = *s.begin();
			s.erase(s.begin());
			cout << cur << endl;
		}

	}

}
