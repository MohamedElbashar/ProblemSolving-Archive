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
#define min(a, b, c) min(min(a, b), c)
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
string s;
int memo[1001][1001];
int solve(int i, int j) {
	if (i > j)
		return 0;
	int &ret = memo[i][j];
	if (ret != -1) {
		return ret;
	}
	if (s[i] == s[j]) {
		return ret = solve(i + 1, j - 1);
	} else {

		ret = min(solve(i + 1, j) + 1, solve(i, j - 1) + 1,//i+1 delete   i insert  i+1,j-1 replace
				solve(i + 1, j - 1) + 1);
		return ret;

	}

}
int t, cnt;
int main() {
	file();
	scan(t);
	while (t--) {
		mem(memo, -1);
		cin >> s;
		int len = s.length() - 1;
		int x = solve(0, len);
		printf("Case %d: %d\n", ++cnt, x);
	}
}
