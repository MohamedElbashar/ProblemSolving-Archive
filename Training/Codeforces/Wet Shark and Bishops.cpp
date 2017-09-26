#include <bits/stdc++.h>
using namespace std;
/**************BASHAR*****************/
struct node {
	int v, u, c;
	node(int v, int u, int c) :
			v(v), u(u), c(c) {
	}
	bool operator <(const node &e) const {
		return c > e.c;
	}
};
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define rep( i, n ) 	for (int i = 0; i < (n); i++)
#define scan(n) scanf("%d",&n)
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
#define oo 1e9
#define fir first
#define sec second
int di[] = { 1, -1, 0, 0 };
int dj[] = { 0, 0, 1, -1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//	freopen("out.txt", "w", stdout);
#else
	// online submission
	//freopen("interesting.in", "r", stdin);
#endif
}
/**************BASHAR*****************/
int n;
map<int, int> mp, mp2;
int main() {
	file();
	scan(n);
	rep(i,n)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		mp[x + y]++;
		mp2[x - y]++;
	}
	int ans = 0;
	for (auto i : mp)
		ans += i.second * (i.second - 1) / 2;

	for (auto i : mp2)
		ans += i.second * (i.second - 1) / 2;
	cout << ans;
}
