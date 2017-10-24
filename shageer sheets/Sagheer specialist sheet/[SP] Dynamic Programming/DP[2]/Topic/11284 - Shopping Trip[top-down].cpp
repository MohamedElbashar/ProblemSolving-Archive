#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pi> vpi;
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define mem(a,b) memset(a,b,sizeof a)
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
	//freopen("sets.in", "r", stdin);
#endif
}
#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\/\/\/\/\/\/\/
int t, n, m, u, v, q, dists[51][51], memo[51][1 << 12], arr[51][51], sv[51],
		vals[51], c, rem;
char e;
int tsp(int pos, int bitmask) {
	if (bitmask == (1 << q) - 1)
		return -dists[pos][0];
	int &ret = memo[pos][bitmask];
	if (ret != -1) {
		return ret;
	}
	ret = -dists[pos][0];
	for (int i = 0; i < n; i++)
		if (vals[i] != -1 && !(bitmask & (1 << vals[i])))
			ret = max(ret,
					sv[i] - dists[pos][i] + tsp(i, bitmask | (1 << vals[i])));
	return ret;
}
int main() {
	file();
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		n++, mem(arr, 0), mem(dists, 5), mem(memo, -1), mem(sv, 0), mem(vals,
				-1), mem(memo, -1);
		mem(arr, 0);
		for (int i = 0; i < m; i++) {
			cin >> u >> v >> c >> e >> rem;
			int cost = c * 100 + rem;
			if (arr[u][v]) {
				cost = min(cost, dists[u][v]);
			}
			arr[u][v] = arr[v][u] = 1;
			dists[u][v] = dists[v][u] = cost;
		}
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]);
				}
			}
		}
		for (int i = 0; i < n; i++) {
			dists[i][i] = 0;
		}
		scanf("%d", &q);
		for (int i = 0; i < q; i++) {
			cin >> u >> c >> e >> rem;
			int cost = c * 100 + rem;
			sv[u] = cost, vals[u] = i;
		}
		int res = tsp(0, 0);
		if (!res) {
			puts("Don't leave the house");
		} else
			printf("Daniel can save $%.2lf\n", double((res * 1.0) / 100));
	}
	return 0;
}
