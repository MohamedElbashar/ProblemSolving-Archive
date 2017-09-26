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
	freopen("out.txt", "w", stdout);
#else
	// online submission
	//freopen("interesting.in", "r", stdin);
#endif
}
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\/\/\/\/\/\/
ll n, x, y, flag;
ll can(ll mid, int j) {
	ll res = (mid * mid * mid) - (j * j * j);
	return res;
}
int main() {
	file();
	while (scanf("%d", &n) && n) {
		flag = 0;
		x = 0, y = 0;
		for (int j = 1; j <= sqrt(n); j++) {
			int st = 1, en = n, mid;
			for (int i = 0; i < 50; i++) {
				mid = st + (en - st) / 2;
				ll xx = can(mid, j);
				if (xx < n) {
					st = mid;
				} else if (xx > n) {
					en = mid;
				} else {
					flag = 1, x = mid, y = j;
					break;
				}
			}
			if (flag)
				break;
		}
		if (flag)
			printf("%d %d\n", x, y);
		else
			printf("No solution\n");
	}

}
