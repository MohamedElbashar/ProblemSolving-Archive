#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define ll long long
#define mem(a,b) memset(a,b,sizeof a)
#define oo 1e8
#define minn(a, b, c) min(min(a, b), c)
#define maxx(a, b, c) max(max(a, b), c)
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int di[] = { 0, -1, 0, 1 };
int dj[] = { 0, 1, 1, 1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
#else
	// online submission
	//freopen("interesting.in", "r", stdin);
#endif
}

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\/\/\/\/\/\/
int t, n;
string s1, s2;

int parent[100001];
int arr[100001];
int par(int x) {
	if (parent[x] == x)
		return x;
	else
		return parent[x] = par(parent[x]);
}
void union_f(int n) {
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
		arr[i] = 1;
	}
}

int link(int x, int y) {
	x = par(x), y = par(y);
	if (x != y) {
		if (arr[x] > arr[y]) {
			parent[y] = x;
			arr[x] += arr[y];
			return arr[x];
		}
		parent[x] = y;
		arr[y] += arr[x];
		return arr[y];
	}
	return arr[x];
}

int main() {
	file();
	scanf("%d", &t);
	while (t--) {
		map<string, int> mp;
		int cnt = 0;
		scanf("%d", &n);
		union_f(min(2 * n, 100000));
		for (int i = 0; i < n; i++) {
			cin >> s1 >> s2;
			int xx = mp[s1], yy = mp[s2];
			if (xx == 0) {
				mp[s1] = ++cnt;
				xx = cnt;
			}
			if (yy == 0) {
				mp[s2] = ++cnt;
				yy = cnt;
			}
			int ans = link(xx, yy);
			printf("%d\n", ans);
		}
	}

}
