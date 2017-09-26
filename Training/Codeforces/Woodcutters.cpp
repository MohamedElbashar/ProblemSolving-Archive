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
ll n, x[100001], h[100001];
int memo[10001];
int solve(int i, int prev) {
	if (i >= n - 1)
		return 0;
	int &ret = memo[i];
	if (ret != -1) {
		return ret;
	}

	int ret1 = 0, ret2 = 0;
	ret = 0;

	if (prev < x[i] - h[i]) {	//wara
		ret1 = solve(i + 1, x[i]) + 1;
	} else if (x[i] + h[i] < x[i + 1]) {//odam
		ret1 = solve(i + 1, h[i] + x[i]) + 1;
	}
	ret2 = solve(i + 1, x[i]);
	return ret = max(ret1, ret2);
}
int main() {
	file();
	scan(n);
	mem(memo, -1);
	rep(i,n)
	{
		cin >> x[i] >> h[i];
	}
	if (n < 3) {
		cout << n;
		return 0;
	} else {
		int xx = solve(1, x[0]);
		cout << xx + 2;
	}
}
