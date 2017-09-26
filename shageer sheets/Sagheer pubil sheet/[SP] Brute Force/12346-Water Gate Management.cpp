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
#define all(v) v.begin(), v.end()
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
int n, q, ci;
pair<ll, ll> arr[21];
int main() {
	file();
	scanf("%d", &n);
	ll e, u;
	for (int i = 0; i < n; i++) {
		scanf("%I64d%I64d", &e, &u);
		arr[i]= {e,u};
	}
	scanf("%d", &q);
	int x, y;
	for (int i = 0; i < q; i++) {
		scanf("%d%d", &x, &y);
		ll ans = oo, cos = oo;
		int flag = 1;
		for (int i = 0; i < (1 << n); i++) {
			ll sum = 0, cost = 0;
			for (int j = 0; j < n; j++) {
				if (i & (1 << j)) {
					sum += (arr[j].first * y);
					cost += arr[j].second;
				}
			}
			if (sum >= x) {
				if (ans > sum && cos > cost) {
					ans = max(ans, sum);
					cos = cost;
					flag = 0;
				}
			}
		}
		if (!flag)
			printf("Case %d: %d\n", ++ci, cos);
		else
			printf("Case %d: IMPOSSIBLE\n", ++ci);
	}
}
