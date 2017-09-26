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
int n, k;
int can(int x) {
	int res = 0, s = 0;
	while ((x /(int) pow(k, s))) {
		res += (x / pow(k, s));
		s++;
	}
	return res >= n;
}
int main() {
	file();
	scanf("%d%d", &n, &k);
	int st = 0, en = n, mid, ans = 1;
	while (st <= en) {
		mid = (st + en) / 2;
		if (can(mid))
			en = mid - 1, ans = mid;
		else
			st = mid + 1;
	}
	printf("%d", ans);
}
