#include <bits/stdc++.h>
using namespace std;
/**************BASHAR*****************/
struct node {
	int u, v, c;
	node(int u, int v, int c) :
			u(u), v(v), c(c) {
	}
	bool operator <(const node &e) const {
		return c > e.c;
	}
};
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define rep( i, n ) for (int i = 0; i < (n); i++)
#define scan(n) scanf("%d",&n)
#define scanl(n) scanf("%I64d",&n)
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
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
/**************BASHAR*****************/
ll divisors(ll x) {
	ll limit = x;
	ll numberOfDivisors = 0;

	if (x == 1)
		return 1;

	for (ll i = 1; i < limit; ++i) {
		if (x % i == 0) {
			limit = x / i;
			if (limit != i) {
				numberOfDivisors++;
			}
			numberOfDivisors++;
		}
	}

	return numberOfDivisors;
}
int a, b, c;
ll res, ans, num, cur;
ll arr[10000001];
int main() {
	file();
	mem(arr, -1);
	scanf("%d%d%d", &a, &b, &c);
	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) {
			for (int k = 1; k <= c; k++) {
				num = i * j * k;
				if (arr[num] != -1)
					ans += arr[num];
				else {
					cur = divisors(num);
					ans += cur;
					arr[num] = cur;
				}

			}
		}
	}
	ll mod = 1073741824;
	if (ans > mod) {
		res = ans % mod;
		cout << res;
	} else {
		cout << ans;
	}
}
