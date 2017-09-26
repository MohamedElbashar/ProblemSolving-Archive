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
int n, k, arr[10001], mx;
double s, q;
int can(double mid) {
	double res = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > mid) {
			q = ((arr[i] - mid) - ((arr[i] - mid) * (k / 100.0)));
			res += q;
		} else
			res -= (mid - arr[i]);
	}
	return res > 0;
}
int main() {
	file();
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		mx = max(mx, arr[i]);
	}
	double st = 0, en = mx, mid, ans;
	for (int i = 0; i < 80; i++) { //log(en-st)/EPS
		mid = (st + en) / 2.0;
		if (can(mid))
			st = mid, ans = mid;
		else
			en = mid;
	}
	printf("%.9lf", ans);

}
