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
#define oo 1e15
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
int t, n, q, l, r;
int arr[200001];
int cnt[10001];
int solve() {
	int l, r;
	scanf("%d%d", &l, &r);

	if (r - l >= 1e4)
		return 0;
	mem(cnt, 0);

	for (int i = l; i <= r; i++) {
		cnt[arr[i]]++;
		if (cnt[arr[i]] == 2)
			return 0;
	}
	int mv = -1e4, ret = 1e4;
	for (int i = 1; i <= 1e4; i++) {
		if (cnt[i]) {
			ret = min(ret, i - mv);
			mv = i;
		}
	}
	return ret;
}
int main() {
	file();
	scan(t);
	while (t--) {
		scan(n);
		for (int i = 1; i <= n; i++) {
			scan(arr[i]);
		}
		scan(n);
		rep(i,n)
		{
			printf("%d\n", solve());
		}
	}
	return 0;
}
