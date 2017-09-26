#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll, int> pi;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pi> vpi;
#define PI 3.1415926535897932384626433832795
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define mem(a,b) memset(a,b,sizeof a)
#define oo LLONG_MAX
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
int n, m, uu, vv, c;
ll dist[100001];
int route[100001];
vpi arr[100001];
void dijkstra(int s) {
	priority_queue<pair<int, ll> > pq;
	pq.push(pi(0, s));
	while (!pq.empty()) {
		pi front = pq.top();
		pq.pop();
		int u = front.second;
		for (int j = 0; j < sz(arr[u]); j++) {
			pi v = arr[u][j];
			if (dist[u] + v.second < dist[v.first]) {
				dist[v.first] = dist[u] + v.second;
				route[v.first] = u;
				pq.push(pi(-dist[v.first], v.first));
			}
		}
	}
}
void printPath(int s) {
	if (route[s])
		printPath(route[s]);
	printf("%d ", s);
}

int main() {
	file();
	scanf("%d%d", &n, &m);
	fill_n(dist + 1, n, LLONG_MAX);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &uu, &vv, &c);
		arr[uu].push_back(mp(vv, c));
		arr[vv].push_back(mp(uu, c));
	}
	dist[1] = 0;
	dijkstra(1);
	if (dist[n] == LLONG_MAX)
		puts("-1");
	else {
		printPath(n);
	}

}
