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
int n, m, u, v, c, sr, des, tot, vis[101], res = oo, cont;
vector<pair<int, pi>> arr;
vpi path[101];
class UnionFind {
private:
	vi p, rank, setSize;
	int numSets;
public:
	UnionFind(int N) {
		setSize.assign(N + 1, 1);
		numSets = N;
		rank.assign(N + 1, 0);
		p.assign(N + 1, -1);
		for (int i = 1; i <= N; i++)
			p[i] = i;
	}
	int findSet(int i) {
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
	}
	bool isSameSet(int i, int j) {
		return findSet(i) == findSet(j);
	}
	void unionSet(int i, int j) {
		if (!isSameSet(i, j)) {
			numSets--;
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]) {
				p[y] = x;
				setSize[x] += setSize[y];
			} else {
				p[x] = y;
				setSize[y] += setSize[x];
				if (rank[x] == rank[y])
					rank[y]++;
			}
		}
	}
	int numDisjointSets() {
		return numSets;
	}
	int sizeOfSet(int i) {
		return setSize[findSet(i)];
	}
};
int dfs(int st, int en) {
	if (st == en)
		return true;
	vis[st] = 1;
	for (int i = 0; i < sz(path[st]); i++) {
		pi cur = path[st][i];
		if (!vis[cur.first]) {
			int xx = dfs(cur.first, en);
			if (xx)
				return res = min(res, cur.second);
		}
	}
	return false;
}
int main() {
	file();
	while (scanf("%d%d", &n, &m) && n) {
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &u, &v, &c);
			arr.push_back(mp(c, mp(u, v)));
		}
		scanf("%d%d%d", &sr, &des, &tot);
		UnionFind uf(n);
		mem(vis, 0), res = oo;
		sort(arr.rbegin(), arr.rend());
		for (int i = 0; i < sz(arr); i++) {
			pair<int, pi> cur = arr[i];
			if (!uf.isSameSet(cur.second.first, cur.second.second)) {
				uf.unionSet(cur.second.first, cur.second.second);
				path[cur.second.first].push_back(
						{ cur.second.second, cur.first });
				path[cur.second.second].push_back(
						{ cur.second.first, cur.first });
			}
		}
		dfs(sr, des);
		printf("Scenario #%d\nMinimum Number of Trips = %d\n\n", ++cont,
				(tot + res - 2) / (res - 1));
		for (int i = 0; i < n + 1; i++) {
			path[i].clear();
		}
		arr.clear();

	}
}
