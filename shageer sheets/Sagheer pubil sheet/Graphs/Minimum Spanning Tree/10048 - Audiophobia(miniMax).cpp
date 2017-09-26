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
int n, m, q, u, v, c, vis[1001], mx;
vector<pair<int, pi>> arr;
vpi path[1001];
class UnionFind {
private:
	vi p, rank, setSize;
	int numSets;
public:
	UnionFind(int N) {
		setSize.assign(N + 1, 1);
		numSets = N;
		rank.assign(N + 1, 0);
		p.assign(N + 1, 0);
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
int tt;
int dfs(int u, int v) {
	if (u == v)
		return true;
	vis[u] = true;
	for (int i = 0; i < sz(path[u]); i++) {
		pi cur = path[u][i];
		if (!vis[cur.first] && dfs(cur.first, v)) {
			mx = max(mx, cur.second);
			return true;
		}
	}
	return false;
}
int main() {
	file();
	/*3a4an ageb el path h3ml array of vector w hbuild graph 3ade 5ales
	 * w a3ml dfs 3ala el graph da w ageb el max path meno
	 */
	while (scanf("%d%d%d", &n, &m, &q) && n) {

		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &u, &v, &c);
			arr.push_back(mp(c, mp(u, v)));
		}
		UnionFind UF(n);
		if (tt)
			printf("\n");
		printf("Case #%d\n", ++tt);
		sort(arr.begin(), arr.end());
		for (int i = 0; i < sz(arr); i++) {
			pair<int, pi> cur = arr[i];
			if (!UF.isSameSet(cur.second.first, cur.second.second)) {
				UF.unionSet(cur.second.first, cur.second.second);
				path[cur.second.first].push_back(
						{ cur.second.second, cur.first });
				path[cur.second.second].push_back(
						{ cur.second.first, cur.first });

			}
		}
		for (int i = 0; i < q; i++) {
			scanf("%d%d", &u, &v);
			if (!UF.isSameSet(u, v)) {
				printf("no path\n");
				continue;
			} else {
				mem(vis, 0);
				mx = 0;
				dfs(u, v);
				printf("%d\n", mx);
			}
		}
		for (int i = 1; i <= n + 1; i++) {
			path[i].clear();
		}
		arr.clear();
	}
}
