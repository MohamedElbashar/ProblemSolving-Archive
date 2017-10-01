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
int t, n, m, x, memo[1001][101];
pi arr[1001];
int solve(int ind, int rem) {
	if (ind == n)
		return 0;
	int &ret = memo[ind][rem];
	if (ret != -1)
		return ret;
	int res1 = solve(ind + 1, rem);
	int res2 = 0;
	if (rem >= arr[ind].second)
		res2 = solve(ind + 1, rem - arr[ind].second) + arr[ind].first;
	return ret = max(res1, res2);

}
int main() {
	file();
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &arr[i].first, &arr[i].second);
		}
		scanf("%d", &m);
		int tot = 0;
		for (int i = 0; i < m; i++) {
			scanf("%d", &x);
			mem(memo, -1);
			tot += solve(0, x);

		}
		printf("%d\n", tot);
	}

}

