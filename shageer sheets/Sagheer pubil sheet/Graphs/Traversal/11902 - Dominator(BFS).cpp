#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define PI 3.1415926535897932384626433832795
#define ll long long
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
int t, n, x;
vi arr[101];
int vis[101], rech[101], cnt;
/*void dfs(int cur, int x) {
 if (cur == x)
 return;
 vis[cur] = 1;
 for (int i = 0; i < (int) arr[cur].size(); i++)
 if (!vis[arr[cur][i]])
 dfs(arr[cur][i], x);
 }*/
void BFS(int cur, int x) {
	queue<int> q;
	q.push(cur), vis[cur] = 1;
	while (q.size()) {
		int xx = q.front();
		q.pop();
		vis[xx] = 1;
		if (xx == x)
			continue;

		for (int i = 0; i < sz(arr[xx]); i++) {
			if (!vis[arr[xx][i]]) {
				q.push(arr[xx][i]);
			}
		}
	}
}
void line() {
	printf("+");
	for (int i = 0; i < (n << 1) - 1; i++)
		printf("-");
	printf("+");
}
void clr() {
	for (int i = 0; i < n; i++) {
		arr[i].clear();
	}
}
int main() {
	file();
	scanf("%d", &t);
	while (t--) {
		mem(vis, 0);
		mem(rech, -1);
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &x);
				if (x)
					arr[i].push_back(j);
			}
		}
		//dfs(0, -1);
		BFS(0, -1);
		for (int i = 0; i < n; i++) {
			rech[i] = vis[i];
		}
		printf("Case %d:\n", ++cnt);
		for (int i = 0; i < n; i++) {
			line();
			printf("\n");
			mem(vis, 0);
			//dfs(0, i);
			BFS(0, i);
			for (int j = 0; j < n; j++) {
				if (j == i && rech[j])
					printf("|Y");
				else {
					if (rech[j] && !vis[j])
						printf("|Y");
					else
						printf("|N");
				}
			}
			printf("|\n");
		}
		line();
		printf("\n");
		clr();
	}

}
