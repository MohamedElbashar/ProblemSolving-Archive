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
int u, v, n, m, cnt[100];
vi arr[100], ans;
void kahn() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (cnt[i] == 0)
			q.push(i);
	}
	int res = 0;
	while (sz(q)) {
		int cur = q.front();
		q.pop();
		ans.push_back(cur);
		for (int i = 0; i < sz(arr[cur]); i++) {
			if (--cnt[arr[cur][i]] == 0) {
				q.push(arr[cur][i]);
			}
		}
		res++;
	}
	if (res != n) {
		printf("There exists a cycle in the graph\n");
		return;
	}
}
int main() {
	file();
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &u, &v);
		arr[u].push_back(v);
		cnt[v]++;
	}
	kahn();
	for (int i = 0; i < sz(ans); i++) {
		printf("%d ", ans[i]);
	}

}

