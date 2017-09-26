#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define PI 3.1415926535897932384626433832795
#define EPS  1e-10
#define ll long long
#define mem(a,b) memset(a,b,sizeof a)
#define oo 1e8
#define minn(a, b, c) min(min(a, b), c)
#define maxx(a, b, c) max(max(a, b), c)
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
	//freopen("interesting.in", "r", stdin);
#endif
}
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\/\/\/\/\/\/
int t, tot, c, n, arr[21][21], memo[201][21];
int solve(int money, int cur) {
	if (money < 0)
		return -oo;
	if (cur == n)
		return tot - money;
	int &ret = memo[money][cur];
	if (ret != -1)
		return ret;
	for (int i = 1; i <= arr[cur][0]; i++) {
		ret = max(ret, solve(money - arr[cur][i], cur + 1));
	}
	return ret;
}
int main() {
	file();
	scanf("%d", &t);
	while (t--) {
		int score = 0;
		scanf("%d%d", &tot, &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i][0]);
			for (int j = 1; j <= arr[i][0]; j++)
				scanf("%d", &arr[i][j]);
		}
		mem(memo, -1);
		score = solve(tot, 0);
		if (score < 0)
			printf("no solution\n");
		else
			printf("%d\n", score);

	}

}
