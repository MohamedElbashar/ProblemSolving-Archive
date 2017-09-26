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
	freopen("out.txt", "w", stdout);
#else
	// online submission
	//freopen("interesting.in", "r", stdin);
#endif
}
/**************BASHAR*****************/
string str1, str2;
int memo[101][101], cnt;
int solve(int i, int j) {
	int &ret = memo[i][j];
	if (i == str1.length() || j == str2.length())
		return 0;
	if (ret != -1)
		return ret;
	if (str1[i] == str2[j])
		return solve(i + 1, j + 1) + 1;
	int res1 = solve(i + 1, j);
	int res2 = solve(i, j + 1);
	return ret = max(res1, res2);
}
int main() {
	file();
	while (getline(cin, str1) && getline(cin, str2) && str1[0] != '#') {
		mem(memo, -1);
		cout << "Case " << '#' << ++cnt << ": you can visit at most "
				<< solve(0, 0) << " cities." << endl;
	}
}
