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
int V, s;

vector<pi> AdjList[100];
void printPath(int u) { 	// extract information from ‘vi p’
	if (u == s) {
		printf("%d", s);
		return;
	} 	// base case, at the source s
	printPath (p[u]); 	// recursive: to make the output format: s -> ... -> t
	printf(" %d", u);
}
int main() {
	vi dist(V, oo);
	dist[s] = 0; // distance from source s to s is 0
	queue<int> q;
	q.push(s);
	vi p; // addition: the predecessor/parent vector
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int j = 0; j < (int) AdjList[u].size(); j++) {
			pi v = AdjList[u][j];
			if (dist[v.first] == oo) {
				dist[v.first] = dist[u] + 1;
				p[v.first] = u; // addition: the parent of vertex v.first is u
				q.push(v.first);
			}
		}
	}
	printPath (t), printf("\n"); // addition: call printPath from vertex t

	vi dist(V, INF);
	dist[s] = 0; // INF = 1B to avoid overflow
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	pq.push(ii(0, s));
	while (!pq.empty()) { // main loop
		ii front = pq.top();
		pq.pop(); // greedy: get shortest unvisited vertex
		int d = front.first, u = front.second;
		if (d > dist[u])
			continue; // this is a very important check
		for (int j = 0; j < (int) AdjList[u].size(); j++) {
			ii v = AdjList[u][j]; // all outgoing edges from u
			if (dist[u] + v.second < dist[v.first]) {
				dist[v.first] = dist[u] + v.second; // relax operation
				pq.push(ii(dist[v.first], v.first));
			}
		}
	} // this variant can cause duplicate items in the priority queue
}
