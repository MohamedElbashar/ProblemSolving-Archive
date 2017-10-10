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
int n, t, k, arr[10001];
bool flag = false;
ll memo[10001][10001];
int solve(int i, int sum) {
	if (flag == true)
		return 0;
	if (i == n) {
		if (sum % k == 0)
			flag = true;
		else
			return 0;
	}
	ll &ret = memo[i][sum];
	if (ret != -1)
		return ret;
	int res = 0;
	res += solve(i + 1, (sum + arr[i]) % k);
	res += solve(i + 1, (sum - arr[i]) % k);
	return ret = res;
}
int main() {
	file();
	scanf("%d", &t);
	while (t--) {
		flag = false;
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		mem(memo, -1);
		solve(0, 0);
		if (flag)
			printf("Divisible\n");
		else
			printf("Not divisible\n");
	}

}
