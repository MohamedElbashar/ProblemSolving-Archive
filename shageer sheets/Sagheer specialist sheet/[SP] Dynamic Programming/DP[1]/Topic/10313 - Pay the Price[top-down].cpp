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
ll memo[302][302][302];
ll solve(long n, int val, int i) {
	if (n == 0 && i == 0)
		return 1;
	if (val > 300 || n < 0 || i == 0)
		return 0;
	ll &ret = memo[n][val][i];
	if (ret != -1)
		return ret;
	return ret = solve(n - val, val, i - 1) + solve(n, val + 1, i);

}
int main() {
	file();
	string s;
	mem(memo, -1);
	while (getline(cin, s)) {
		int val;
		vi v;
		istringstream iss(s);
		while (iss >> val)
			v.push_back(val);
		int n = v[0], st, en;
		ll ans = 0;
		if (sz(v) == 1)
			st = 0, en = v[0];
		else if (sz(v) == 2) {
			st = 0, en = v[1];
		} else {
			st = v[1], en = v[2];
		}
		en = min(en, n);
		for (int i = st; i <= en; i++) {
			ans += solve(n, 1, i);
		}
		printf("%lld\n", ans);
		v.clear();

	}
}

