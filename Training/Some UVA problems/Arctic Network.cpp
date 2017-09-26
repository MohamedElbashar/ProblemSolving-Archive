#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define ll long long
#define mem(a,b) memset(a,b,sizeof a)
#define oo 1e8
#define minn(a, b, c) min(min(a, b), c)
#define maxx(a, b, c) max(max(a, b), c)
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int di[] = { 0, -1, 0, 1 };
int dj[] = { 0, 1, 1, 1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#else
	// online submission
	//freopen("interesting.in", "r", stdin);
#endif
}

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\/\/\/\/\/\/
int t, n, m, from[500], to[500];
int parent[100001];
vector<pair<double, pi>> edges;
int ssize;
int par(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = par(parent[x]);
}
void uni(int x, int y) {
	x = par(x);
	y = par(y);
	if (x != y) {
		parent[x] = y;
		ssize--;
	}

}
void init(int x) {
	for (int i = 0; i < x; i++)
		parent[i] = i;
	ssize = x;
}
int getsize() {
	return ssize;
}
int same(int x, int y) {
	return par(x) == par(y);
}
int main() {
	file();
	scanf("%d", &t);
	while (t--) {
		mem(parent, 0);
		mem(from, 0);
		mem(to, 0);
		edges.clear();
		ssize = 0;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &from[i], &to[i]);
		}
		for (int i = 0; i < m; i++) {
			for (int j = i + 1; j < m; j++) {
				double dis = hypot((double) from[i] - from[j],
						(double) to[i] - to[j]);
				edges.push_back(make_pair(dis, pi(i, j)));
			}
		}

		sort(edges.begin(), edges.end());
		init(m);
		double cnt = 0.0;
		for (int i = 0; getsize() > n; i++) {
			pair<double, pi> top = edges[i];
			if (!same(top.second.first, top.second.second)) {
				uni(top.second.first, top.second.second);
				cnt = max(cnt, top.first);
			}
		}
		cout << fixed << setprecision(2) << cnt << endl;
	}
}
