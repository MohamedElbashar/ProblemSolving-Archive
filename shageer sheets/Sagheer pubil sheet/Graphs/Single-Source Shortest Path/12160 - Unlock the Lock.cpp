#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pi> vpi;
#define EPS 1e-9
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

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\/\/\/\/\/\/\/
int L, R, U, RVs[10000], cnt, dist[10000];
int dij() {
	queue<int> q;
	mem(dist, -1);
	dist[L] = 0;
	q.push(L);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < R; i++) {
			int v = (u + RVs[i]) % 10000;
			if (dist[v] == -1) {
				dist[v] = dist[u] + 1;
				if (v == U)
					return dist[v];
				q.push(v);
			}
		}
	}
	return -1;
}
int main() {
	file();
	while (scanf("%d%d%d", &L, &U, &R), (L || U || R)) {
		for (int i = 0; i < R; i++)
			scanf("%d", &RVs[i]);
		printf("Case %d: ", ++cnt);
		int res = dij();
		if (res == -1)
			printf("Permanently Locked\n");
		else
			printf("%d\n", res);
	}

}
