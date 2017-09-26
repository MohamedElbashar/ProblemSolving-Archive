#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define ll long long
#define mem(a,b) memset(a,b,sizeof a)
#define oo 1e8
#define minn(a, b, c) min(min(a, b), c)
#define maxx(a, b, c) max(max(a, b), c)
int di[] = { 0, -1, 0, 1 };
int dj[] = { 0, 1, 1, 1 };
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
int a, b, c, d;

int main() {
	file();
	scanf("%d%d%d%d", &a, &b, &c, &d);
	double x = (double) a / b;
	double y = (double) c / d;
	if (x < y) {
		int res = b * c;
		int res2 = a * d;
		int ret = res - res2;
		int div = __gcd(ret, res);
		int check1 = (double) res / div;
		int check2 = (double) ret / div;
		if (trunc(check1) - check1 == 0 && trunc(check2) - check2 == 0) {
			ret /= div;
			res /= div;
		}
		printf("%d/%d", ret, res);
		return 0;
	} else if (x > y) {
		int res = a * d;
		int res2 = b * c;
		int ret = res - res2;
		int div = __gcd(ret, res);
		int check1 = (double) res / div;
		int check2 = (double) ret / div;
		if (trunc(check1) - check1 == 0 && trunc(check2) - check2 == 0) {
			ret /= div;
			res /= div;
		}
		printf("%d/%d", ret, res);
		return 0;
	} else {
		printf("%d/%d", 0, 1);
	}

}
