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
	freopen("out.txt", "w", stdout);
#else
	// online submission
	//freopen("interesting.in", "r", stdin);
#endif
}
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\/\/\/\/\/\/
char lar;
int vis[26], cnt = 0, t, to;
vi arr[26];
void dfs(int cur) {
	vis[cur] = 1;
	for (int i = 0; i < sz(arr[cur]); i++)
		if (!vis[arr[cur][i]])
			dfs(arr[cur][i]);
}
void conn_comp(int u) {
	for (int i = 0; i <= to; i++) {
		if (!vis[i]) {
			dfs(i);
			cnt++;
		}
	}
}
void clr() {
	for (int i = 0; i < 26; i++) {
		arr[i].clear();
	}
}
int main() {
	file();
	scanf("%d", &t);
	while (t--) {
		string c;
		mem(vis, 0);
		cnt = 0;
		clr();
		cin >> lar;
		to = lar - 'A';
		getchar();
		while (getline(cin, c) && c[0] != '\0') {
			arr[c[0] - 'A'].push_back(c[1] - 'A');
			arr[c[1] - 'A'].push_back(c[0] - 'A');
		}
		conn_comp(0);
		printf("%d\n", cnt);
		if (t)
			printf("\n");
	}
}

