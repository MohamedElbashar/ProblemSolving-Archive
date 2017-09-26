#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef vector<int> vi;
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
int n, u, v, color[301];
vi arr[301];
bool isbi = true;
void bipartite(int cur) {
	queue<int> q;
	q.push(cur);
	while (sz(q)) {
		int to = q.front();
		q.pop();
		for (int i = 0; i < sz(arr[to]); i++) {
			if (color[arr[to][i]] == -1) {
				color[arr[to][i]] = 1 - color[to];
				q.push(arr[to][i]);
			} else if (color[arr[to][i]] == color[to]) {
				isbi = false;
				return;
			}
		}
	}
}
int main() {
	file();
	while (scanf("%d", &n) && n) {
		mem(color, -1);
		isbi = true;
		for (int i = 0; i < n + 1; i++)
			arr[i].clear();
		while (scanf("%d%d", &u, &v) && u && v) {
			arr[u].push_back(v);
			arr[v].push_back(u);
		}
		color[1] = 0;
		bipartite(1);
		if (isbi)
			printf("YES\n");
		else
			printf("NO\n");
	}

}

