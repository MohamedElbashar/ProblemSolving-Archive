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
vi arr[101], artic;
int dfs_num[101], dfs_low[101], dfs_parent[101], ans, dfsroot, rootchild, n, u,
		v, val, dfsnum;
void Artic(int cur) {
	dfs_low[cur] = dfs_num[cur] = dfsnum++;
	for (int i = 0; i < sz(arr[cur]); i++) {
		int v = arr[cur][i];
		if (dfs_num[v] == -1) {
			dfs_parent[v] = cur;
			if (cur == dfsroot)
				rootchild++;
			Artic(v);
			//if cur is not the root and its child v has no back edge
			//to reach cur (meaning there is no cycle),then cur is atricuation vertex
			if (cur != dfsroot && dfs_low[v] >= dfs_num[cur]) {
				artic[cur] = true;
			}
			dfs_low[cur] = min(dfs_low[cur], dfs_low[v]);
		} else if (v != dfs_parent[cur]) {
			dfs_low[cur] = min(dfs_low[cur], dfs_num[v]);
		}
	}
}
int main() {
	file();
	string s;
	//ageb el artic points bas 3ddhm
	while (scanf("%d\n", &n) && n) {
		artic.clear();
		artic.resize(n + 1, false);
		dfsnum = 0;
		mem(dfs_num,-1), mem(dfs_low, 0), mem(dfs_parent, 0);
		for (int i = 0; i < n + 1; i++) {
			arr[i].clear();
		}
		while (true) {
			getline(cin, s);
			istringstream iss(s);
			iss >> val;
			if (val == 0)
				break;
			u = val;
			while (iss >> val) {
				arr[u].push_back(val);
				arr[val].push_back(u);
			}
		}
		for (int i = 1; i <= n; i++) {
			if (dfs_num[i] == -1) {
				dfsroot = i;
				rootchild = 0;
				Artic(i);
				if (rootchild > 1)
					artic[dfsroot] = true;

			}
		}
		int c = count(all(artic), true);
		printf("%d\n", c);
	}
}
