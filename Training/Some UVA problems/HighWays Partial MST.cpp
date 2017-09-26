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
	//freopen("out.txt", "w", stdout);
#else
	// online submission
	//freopen("interesting.in", "r", stdin);
#endif
}

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\/\/\/\/\/\/
int t, n, m, from[751], to[751], cnt;
int arr[751];
struct edge {
	int from, to;
	double w;
	edge(int from, int to, double w) :
			from(from), to(to), w(w) {

	}
	bool operator <(const edge &e) const {
		return w > e.w;
	}
};
priority_queue<edge> q;
int parent(int x) {
	if (arr[x] == -1)
		return x;
	return arr[x] = parent(arr[x]);
}
void uni(int x, int y) {
	x = parent(x);
	y = parent(y);
	if (x != y)
		arr[x] = y;
}
double dis(int x, int y) {
	return sqrt(pow(from[x] - from[y], 2) + pow(to[x] - to[y], 2));
}
int main() {
	file();
	scanf("%d", &t);
	while (t--) {
		int u, v;
		scanf("%d", &n);
		mem(arr, -1);
		for (int i = 1; i <= n; i++) {
			scanf("%d%d", &from[i], &to[i]);
		}
		scanf("%d", &m);
		for (int i = 1; i <= m; i++) {
			scanf("%d%d", &u, &v);
			uni(u, v);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				q.push(edge(i, j, dis(i, j)));

			}
		}
		while (q.size()) {
			edge e = q.top();
			q.pop();
			if (parent(e.from) != parent(e.to)) {
				uni(e.from, e.to);
				printf("%d %d\n", e.from, e.to);
				cnt++;
			}
		}
		if (!cnt)
			printf("%s", "No new highways need\n");
	}

}
