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
int grid[10][10];
int memo[10][10];
int n;
int valid(int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < n;
}
int solve(int r, int c) {
	if (!valid(r, c))
		return 0;
	if (r == n - 1 && c == n - 1)
		return grid[r][c];
	if (memo[r][c] != -1)
		return memo[r][c];
	int path1 = solve(r, c + 1);
	int path2 = solve(r + 1, c);
	return memo[r][c] = grid[r][c] + max(path1, path2);
}
int main() {
	file();
	mem(memo, -1);
	scan(n);
	for (int i = 0; i < n; i++) {
		rep(j,n)
		{
			scan(grid[i][j]);
		}
	}
	int x = solve(0, 0);
	cout << x;
}

