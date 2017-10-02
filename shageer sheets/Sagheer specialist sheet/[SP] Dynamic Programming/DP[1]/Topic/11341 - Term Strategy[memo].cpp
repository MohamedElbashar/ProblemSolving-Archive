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
	//freopen("sets.in", "r", stdin);
#endif
}
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\/\/\/\/\/\/\/
int t, n, m, arr[12][102], memo[12][102];
int solve(int ind, int tot) {
	if (tot == 0 && ind < n + 1) {
		return -1e9;
	}
	if (ind == n + 1)
		return 0;
	int &ret = memo[ind][tot];
	if (ret != -1)
		return memo[ind][tot];
	int ret2 = -1e10;
	for (int i = 1; i <= m; i++) {
		if (tot >= i && arr[ind][i] >= 5)
			ret2 = max(ret2, solve(ind + 1, tot - i) + arr[ind][i]);
	}
	return ret = ret2;
}
int main() {
	file();
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		mem(memo, -1);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				scanf("%d", &arr[i][j]);
		double xx = double(double(solve(1, m)) + double(1e-9)) / double(n);
		if (xx >= 5) {
			printf("Maximal possible average mark - %.2lf.\n", xx);
		} else
			printf("Peter, you shouldn't have played billiard that much.\n");

	}
}

