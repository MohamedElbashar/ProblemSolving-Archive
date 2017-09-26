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
int t, n;
int arr[101];
int memo[105][50005];
int solve(int i, int b1, int b2) {
	if (i >= n) {
		if (b1 - b2 < 0)
			return b2 - b1;
		else
			return b1 - b2;
	}
	int &ret = memo[i][b1];
	if (ret != -1)
		return ret;
	return ret = min(solve(i + 1, b1 + arr[i], b2),
			solve(i + 1, b1, b2 + arr[i]));

}
int sum;
int main() {
	file();
	scan(t);
	while (t--) {
		scan(n);
		mem(memo, -1);
		rep(i,n)
		{
			scan(arr[i]);
			sum += arr[i];
		}
		cout << solve(0, 0, 0)<<endl;
	}

}
