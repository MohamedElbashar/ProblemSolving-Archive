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

struct edge {
	int u, v, w;
};

edge edges[100000];
vi sec;
int t, n, m, par[1000000], cmst1;
int inmst[1000000];
int parent(int x) {
	if (par[x] == x)
		return x;
	return par[x] = parent(par[x]);
}
void uni(int x, int y) {
	x = parent(x);
	y = parent(y);
	if (x != y)
		par[x] = y;
}
void rest() {
	for (int i = 1; i <= n; i++) {
		par[i] = i;
	}
}
void MST(int xx) {
	rest();
	int cmst2 = 0;
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		if (parent(edges[i].u) != parent(edges[i].v) && i != xx) {
			cmst2 += edges[i].w;
			uni(edges[i].u, edges[i].v);
			cnt++;
		}
	}
	if (cnt == n - 1)
		sec.push_back(cmst2);
}
int cmp(edge a, edge b) {
	return a.w < b.w;
}
int main() {
	file();
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		cmst1 = 0;
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);
			inmst[i] = 0;
		}
		rest();
		sort(edges, edges + m, cmp);
		for (int i = 0; i < m; i++) {
			if (parent(edges[i].u) != parent(edges[i].v)) {
				uni(edges[i].u, edges[i].v);
				cmst1 += edges[i].w;
				inmst[i] = 1;
			}
		}
		//	printf("%d\n", cmst1);
		sec.clear();
		for (int i = 0; i < m; i++) {
			if (inmst[i])
				MST(i);
		}
		sort(sec.begin(), sec.end());
		printf("%d %d\n", cmst1, sec[0]);
	}
}
