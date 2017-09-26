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
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
#define oo 1e15
int di[] = { 1, -1, 0, 0 };
int dj[] = { 0, 0, 1, -1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//	freopen("out.txt", "w", stdout);
#else
	// online submission
	//freopen("interesting.in", "r", stdin);
#endif
}
/**************BASHAR*****************/
int s, k;
int mxk;
ll memo[21][101];
int solve(int k, int rem) {
	if (k == mxk) {
		if (rem == 0)
			return 1;
		return 0;
	}
	if (rem == 0)
		return 0;
	ll &ret = memo[k][rem];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = 1; i <= rem; ++i) {
		ll sol = solve(k + 1, rem - i) * i;
		ret = max(ret, sol);
	}
	return ret;

}
int main() {
	file();
	mem(memo, -1);
	scanf("%d%d", &s, &k);
	mxk = k;
	cout << solve(0, s);
}

