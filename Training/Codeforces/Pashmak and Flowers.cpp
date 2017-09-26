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
#define oo 1e9
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

int main() {
	ll n;
	file();

	scan(n);
	vi v(n);
	rep(i,n)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	ll mxx = upper_bound(v.begin(), v.end(), v[0]) - v.begin();
	ll mn = n - (lower_bound(v.begin(), v.end(), v[n - 1]) - v.begin());
	if (v[0] != v[n - 1])
		cout << v[n - 1] - v[0] << " " << mxx * mn;
	else
		cout << 0 << " " << (n * (n - 1)) / 2;
	return 0;
}
