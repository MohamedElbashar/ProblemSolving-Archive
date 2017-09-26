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
bool exist(vi v, int e) {
	for (int i = 0; i < sz(v); i++)
		if (v[i] == e)
			return true;
	return false;
}

int main() {
	//3a4an a3rf aktr nas htege wala la2 ast5m el bicolor
	//a3lm ele mfe4 beno w ben el tane 3dawa
	//w a4of nas 4abah ba3d w agm3hm
	file();
	int n, m, v, t;
	vector<vi> arr;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		arr.assign(n, vi());
		for (int u = 0; u < n; u++) {
			scanf("%d", &m);
			for (int j = 0; j < m; j++) {
				scanf("%d", &v);
				v--;
				if (v < n) {
					if (!exist(arr[u], v))
						arr[u].push_back(v);
					if (!exist(arr[v], u))
						arr[v].push_back(u);
				}
			}
		}
		vi color(n, -1);
		bool isBipartite;
		int ans = 0;

		for (int s = 0; s < n; s++) {
			if (color[s] != -1)
				continue;

			isBipartite = true;
			int colorCount[2] = { 0, 0 };
			queue<int> q;
			q.push(s);
			color[s] = 0;
			colorCount[0]++;
			while (!q.empty()) {
				int u = q.front();
				q.pop();
				for (int j = 0; j < sz(arr[u]); j++) {
					if (color[arr[u][j]] == -1) {
						color[arr[u][j]] = 1 - color[u];
						colorCount[color[arr[u][j]]]++;
						q.push(arr[u][j]);
					} else if (color[arr[u][j]] == color[u]) {
						isBipartite = false;
					}
				}
			}

			if (isBipartite)
				ans += max(colorCount[0], colorCount[1]);
		}

		printf("%d\n", ans);
	}

	return 0;
}
