#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
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
int N, S;
ll memo[65][65][2];
ll solve(int n, int s, int f) {
	if (n == N) {
		if (s == S)
			return 1;
		else
			return 0;
	}
	ll &ret = memo[n][s][f];
	if (ret != -1)
		return ret;
	ret = 0;
	ret += solve(n + 1, s + 1, 1);
	if (f)
		ret += solve(n + 1, s - 1, 0);
	else
		ret += solve(n + 1, s, 0);
	return ret;
}
int main() {
	file();
	while (scanf("%d%d", &N, &S) && N > 0) {
		mem(memo, -1);
		cout << solve(0, 0, 0);
		printf("\n");

	}

}
