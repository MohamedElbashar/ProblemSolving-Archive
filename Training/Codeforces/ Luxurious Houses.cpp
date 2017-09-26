#include <bits/stdc++.h>
using namespace std;
/**************BASHAR*****************/
struct node {
	int v, c, u;
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
vi v, s;
int main() {
	file();
	scan(n);
	rep(i,n)
	{
		int x;
		scan(x);
		v.push_back(x);
	}
	int x = 0;
	for (int i = n - 1; i >= 0; i--) {
		x = max(v[i], x);
		s.push_back(x);
	}
	reverse(s.begin(), s.end());
	for (int i = 0; i < n; i++) {
		if (v[i] == s[i] && s[i] != s[i + 1]) {
			cout << 0 << " ";
		} else {
			cout << s[i] + 1 - v[i];
		}
	}
}
