#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pi> vpi;
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define mem(a,b) memset(a,b,sizeof a)
#define sz(v) ((int)((v).size()))
#define minn(a, b, c) min(min(a, b), c)
#define maxx(a, b, c) max(max(a, b), c)and
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int di[] = { 1, -1, 0, 0 };
int dj[] = { 0, 0, 1, -1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	// online submission
	//freopen("sets.in", "r", stdin);
#endif
}
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\/\/\/\/\/\/\/
int t, tot, c, n, price[21][21], memo[201][21];
int solve(int money, int cur) {
	if (money < 0)
		return -1e9;
	if (cur == n)
		return tot - money;
	int &ret = memo[money][cur];
	if (ret != -1)
		return ret;
	for (int i = 1; i <= price[cur][0]; i++) {
		ret = max(ret, solve(money - price[cur][i], cur + 1));
	}
	return ret;
}
void print_shop(int money, int g) {
	if (money < 0 || g == n)
		return;
	for (int i = 1; i <= price[g][0]; i++) {
		if (solve(money - price[g][i], g + 1) == memo[money][g]) {
			printf("%d%c", price[g][i], g == n - 1 ? "\n" : "-");
			print_shop(money - price[g][i], g + 1);
			break;
		}

	}
}
int main() {
	file();
	scanf("%d", &t);
	while (t--) {
		int score = 0;
		scanf("%d%d", &tot, &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &price[i][0]);
			for (int j = 1; j <= price[i][0]; j++)
				scanf("%d", &price[i][j]);
		}
		mem(memo, -1);
		score = solve(tot, 0);
		if (score < 0)
			printf("no solution\n");
		else
			printf("%d\n", score);

	}

}
