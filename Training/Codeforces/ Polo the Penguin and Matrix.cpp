#include <bits/stdc++.h>
using namespace std;
/**************BASHAR*****************/
struct node {
	int u, v, c;
	node(int u, int v, int c) :
			u(u), v(v), c(c) {
	}
	bool operator <(const node &e) const {
		return c > e.c;
	}
};
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define rep( i, n ) for (int i = 0; i < (n); i++)
#define scan(n) scanf("%d",&n)
#define scanl(n) scanf("%I64d",&n)
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
#define oo 1e8
#define minn(a, b, c) min(min(a, b), c)
#define maxx(a, b, c) max(max(a, b), c)
int di[] = { 0, -1, 0, 1 };
int dj[] = { 0, 1, 1, 1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	// online submission
	//freopen("interesting.in", "r", stdin);
#endif
}
/**************BASHAR*****************/
int n, m, d, x, cnt;
int vis[10001];
int main() {
	file();
	vi v(n * m);
	mem(vis, -1);
	scanf("%d%d%d", &n, &m, &d);
	for (int i = 0; i < n * m && scan(x); i++) {
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	int ret = oo;
	if (v[0] == v[v.size() - 1]) {
		printf("%d", 0);
		return 0;
	}
	int ans = v[(v.size() / 2)];
	for (int i = 0; i < v.size(); i++) {
		int res = abs(v[i] - ans);
		if (res % d != 0) {
			printf("%d", -1);
			return 0;
		} else {
			cnt += res / d;
		}
	}
	printf("%d", cnt);
}

