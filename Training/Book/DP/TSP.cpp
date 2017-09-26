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
int n, arr[100];
int memo[100][100];
int solve(int i, int prev) {
	if (i == n)
		return 0;
	int &ret = memo[i][prev];
	if (ret != -1)
		return memo[i][prev];
	int choice1 = solve(i + 1, prev);
	int choice2 = 0;
	if (arr[i] >= arr[prev] && i != prev)
		choice2 = solve(i + 1, i) + 1;
	return ret = max(choice1, choice2);
}
int main() {
	file();
	mem(memo, -1);
	scan(n);
	rep(i,n)
	{
		scan(arr[i]);
	}
	cout << solve(0, 0);
}

