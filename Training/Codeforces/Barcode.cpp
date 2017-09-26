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
#define oo 1e9
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
int cnt[1001];
int n, m, x, y;
int memo[1001][1001][3];
int solve(int i, int width, int flag) {
	if (i == m) {
		if (width < x || width > y)
			return oo;
		return 0;
	}
	int &ret = memo[i][width][flag];
	if (ret != -1)
		return ret;
	int retdots = oo;
	if (i == 0 || (flag == 0 && width + 1 <= y) || (flag == 1 && width >= x))
		retdots = n - cnt[i] + solve(i + 1, (flag == 0) ? width + 1 : 1, 0);
	int rethash = oo;
	if (i == 0 || (flag == 1 && width + 1 <= y) || (flag == 0 && width >= x))
		rethash = cnt[i] + solve(i + 1, (flag == 1) ? width + 1 : 1, 1);
	ret = min(retdots, rethash);
	return ret;
}
int main() {
	file();
	scanf("%d%d%d%d", &n, &m, &x, &y);
	mem(memo, -1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			if (c == '.')
				cnt[j]++;
		}
	}
	int res = solve(0, 0, 2);
	cout << res;

}
