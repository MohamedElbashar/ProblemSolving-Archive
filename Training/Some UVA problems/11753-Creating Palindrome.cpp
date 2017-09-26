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
int t, n, k, cnt;
int arr[10001];
int res = 0;
int memo[10001][10001];
int solve(int i, int j) {
	int &ret = memo[i][j];
	if (i >= j)
		return cnt;
	if (ret > k)
		return oo;
	if (ret != -1)
		return memo[i][j];
	if (arr[i] == arr[j]) {
		ret = solve(i + 1, j - 1);
	} else {
		ret = min(solve(i + 1, j) + 1, solve(i, j - 1) + 1);
	}
	return ret;
}
int main() {
	file();
	scan(t);
	while (t--) {
		mem(memo, -1);
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; i++) {
			scan(arr[i]);
		}
		int x = solve(0, n - 1);
		if (x == 0) {
			cout << "Case " << ++cnt << ": Too easy" << endl;
		} else if (x > k) {
			cout << "Case " << ++cnt << ": Too difficult" << endl;
		} else {
			cout << "Case " << ++cnt << ": " << x << endl;
		}
	}
}
