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
int n;
int r[100], g[100], b[100];
int memo[100][4];
int solve(int i, int lastcolor) {
	if (i == n)
		return 0;
	int &ret = memo[i][lastcolor];
	if (ret != -1)
		return ret;
	ret = oo;
	if (lastcolor != 0) {
		ret = min(ret, r[i] + solve(i + 1, 0));
	}
	if (lastcolor != 1) {
		ret = min(ret, g[i] + solve(i + 1, 1));
	}
	if (lastcolor != 2) {
		ret = min(ret, b[i] + solve(i + 1, 2));
	}
	return ret;
}
int main() {
	file();
	scan(n);
	mem(memo, -1);
	rep(i,n)
	{

		cin >> r[i] >> g[i] >> b[i];
	}
	int x = solve(0, 3);
	cout << x;
}

