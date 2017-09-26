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
#define oo 1e6
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
int n, m, u, v, color[201];
vi arr[201];
bool isbi = true;
void BIPARTITE(int x) {
	queue<int> q;
	q.push(x);
	color[x] = 0;
	//b3lm awl node 0
	//b4of kol el neighbours bto3o w adehm lon tane
	//lw gale en el node ele ray7lha el color bta3ha bysawe ele ana gay menha keda false
	while (sz(q) && isbi) {
		int to = q.front();
		q.pop();
		for (int i = 0; i < sz(arr[to]); i++) {
			if (color[arr[to][i]] == -1) {
				color[arr[to][i]] = 1 - color[to];
				q.push(arr[to][i]);
			} else if (color[arr[to][i]] == color[to]) {
				isbi = false;
				break;
			}
		}
	}
}

int main() {
	file();

	while (scanf("%d%d", &n, &m) && n) {
		mem(color, -1);
		isbi = true;
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &u, &v);
			arr[u].push_back(v);
		}
		BIPARTITE(0);
		if (isbi)
			printf("BICOLORABLE.\n");
		else
			printf("NOT BICOLORABLE.\n");
		for (int i = 0; i < n; i++)
			arr[i].clear();

	}

}

