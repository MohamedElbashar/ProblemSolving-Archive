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
int n, w, arr[100], val[100];
int memo[100][100];

int solve(int i, int rem) {
	if (i == n)
		return 0;
	if (memo[i][rem] != -1)
		return memo[i][rem];
	int choice1 = solve(i + 1, rem);
	int choice2 = 0;
	if (rem >= arr[i])
		choice2 = solve(i + 1, rem - arr[i]) + val[i];
	return memo[i][rem] = max(choice1, choice2);
}
int main() {
	file();
	scan(n);
	mem(memo, -1);
	scan(w);
	rep(i,n)
	{
		scan(arr[i]);
	}
	rep(i,n)
	{
		scan(val[i]);
	}

	cout << solve(0, w);
}

