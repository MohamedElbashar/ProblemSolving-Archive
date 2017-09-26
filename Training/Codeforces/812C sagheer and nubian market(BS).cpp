#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define PI 3.1415926535897932384626433832795
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
int n, arr[100001];
ll s, tst[100001];
ll can(int m) {
	ll ans = 0;
	mem(tst, -1);
	for (int i = 0; i < n; i++) {
		tst[i] = arr[i] + (m * (ll) (i + 1));
	}
	sort(tst, tst + n);
	for (int i = 0; i < m; i++)
		ans += tst[i];
	return ans;
}
int main() {
	file();
	scanf("%d%I64d", &n, &s);
	for (int i = 0; i < n; scanf("%d", &arr[i]), i++)
		;
	int st = 0, en = n, mid, res = 0;
	ll tot = 0, anss = 0;
	while (st <= en) {
		mid = st + (en - st) / 2;
		anss = can(mid);
		if (anss <= s) {
			res = mid;
			tot = anss;
			st = mid + 1;
		} else
			en = mid - 1;
	}
	printf("%d %I64d", res, tot);
}
