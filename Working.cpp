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
int n, k, dp[105][105];
int main() {
	file();
	mem(dp, 0);
	for (int i = 0; i <= 100; i++) {
		dp[i][1] = 1;
	}
	for (int j = 1; j < 100; j++) {
		for (int i = 0; i <= 100; i++) {
			for (int k = 0; k <= 100 - i; k++) {
				dp[i + k][j + 1] += dp[i][j];
				dp[i + k][j + 1] %= 1000000;

			}
		}
	}
	while (scanf("%d%d", &n, &k) && (n || k)) {
		printf("%d\n", dp[n][k]);
	}
}

