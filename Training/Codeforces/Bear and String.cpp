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
int valid(string a, int i) {
	return a[i] == 'b' && a[i + 1] == 'e' && a[i + 2] == 'a' && a[i + 3] == 'r';
}
vpi v;
int cnt;
int main() {
	file();
	string s;
	cin >> s;
	for (int i = 0; i <= s.size(); i++) {
		if (valid(s, i)) {
			v.push_back(make_pair(i + 1, i + 3));
		}
	}
	int len = s.length();
	int yy = 0;
	for (int i = 0; i < v.size(); i++) {
		int xx = v[i].first - yy;
		cnt += xx * (len - v[i].second);
		yy = v[i].first;
	}
	printf("%d", cnt);
}
