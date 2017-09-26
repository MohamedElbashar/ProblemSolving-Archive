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
#define EPS 1e-4
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\/\/\/\/\/\/

int route[12];

void dijkstra(int s, vi *dist, vector<vpi> *graph) {
	priority_queue<pi, vector<pi>, greater<pi> > pq;
	pq.push(pi(0, s));
	while (!pq.empty()) {
		pi front = pq.top();
		pq.pop();
		int d = front.first, u = front.second;
		if (d == dist->at(u))
			for (int j = 0; j < (int) graph->at(u).size(); j++) {
				pi v = graph->at(u)[j];             // all outgoing edges from u
				if (dist->at(u) + v.second < dist->at(v.first)) {
					dist->at(v.first) = dist->at(u) + v.second; // relax operation
					route[v.first] = u;
					pq.push(pi(dist->at(v.first), v.first));
				}
			}
	}
}

void printPath(int s, int t) {
	if (s == t) {
		printf("%d", t);
		return;
	}
	printPath(route[s], t);
	printf(" %d", s);
}

int main() {
	file();
	int N, cases = 1;
	while (scanf("%d", &N) && N) {
		memset(route, -1, sizeof route);
		vector<vpi> graph(N + 1, vpi());
		for (int i = 1; i <= N; i++) {
			int relations, v, w;
			scanf("%d", &relations);
			for (int j = 0; j < relations; ++j) {
				scanf("%d %d", &v, &w);
				graph[i].push_back(pi(v, w));
			}
		}
		int s, t;
		scanf("%d %d", &s, &t);
		vi dist(N + 1, oo);
		dist[s] = 0;
		dijkstra(s, &dist, &graph);
		printf("Case %d: Path = ", cases++);
		printPath(t, s);
		printf("; %d second delay\n", dist[t]);

	}

	return 0;

}
