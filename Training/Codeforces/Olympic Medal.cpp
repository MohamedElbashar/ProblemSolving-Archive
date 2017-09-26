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
#define rep( i, n ) for (int i = 0; i < (n); i++)
#define scan(n) scanf("%d",&n)
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
#define oo 1e9
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
int n, m, k, a, b;
vi r1, p1, p2;
int main() {
	file();
	scan(n);
	rep(i,n)
	{
		int x;
		scan(x);
		r1.push_back(x);
	}
	scan(m);
	rep(i,m)
	{
		int x;
		scan(x);
		p1.push_back(x);
	}
	scan(k);
	rep(i,k)
	{
		int x;
		scan(x);
		p2.push_back(x);
	}
	scanf("%d%d", &a, &b);
	int mxr1 = *max_element(r1.begin(), r1.end());
	int mxp1 = *max_element(p1.begin(), p1.end());
	int mnp2 = *min_element(p2.begin(), p2.end());
	double ans=(double)(b * mxp1) / (b * mxp1 + a * mnp2);
	double res = (double)mxr1 * (sqrt(ans));
	cout << fixed << setprecision(12) << res;
}
