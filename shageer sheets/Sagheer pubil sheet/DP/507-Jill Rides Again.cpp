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
int n, x, t, cnt;
int main() {
	file();
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int sum = 0, ans = 0, f  =1, s = 0, tmp=1;
		for (int i = 2; i <= n; i++) {
			scanf("%d", &x);
			sum += x;
			if (sum < 0)
				sum = 0, tmp = i;
			if (ans < sum || (sum == ans && (i - tmp > s - f))) {
				ans = sum;
				f = tmp;
				s = i;
			}

		}
		if (ans > 0)
			printf("The nicest part of route %d is between stops %d and %d\n",
					++cnt, f, s);
		else
			printf("Route %d has no nice parts\n", ++cnt);
	}
}

