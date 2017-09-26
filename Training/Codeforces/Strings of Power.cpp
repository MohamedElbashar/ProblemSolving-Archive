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
string s;
vector<int> vm;
vector<int> vh;
ll cnt, hh;
/*int validh(string a, int i) {
	return s[i] == 'h' && s[i + 1] == 'e' && s[i + 2] == 'a' && s[i + 3] == 'v'
			&& s[i + 4] == 'y';
}
int validy(string a, int i) {
	return s[i] == 'm' && s[i + 1] == 'e' && s[i + 2] == 't' && s[i + 3] == 'a'
			&& s[i + 4] == 'l';
}*/
int main() {
	file();
	cin >> s;
	int len = s.length();
	for (int i = 0; i < len; i++) {
		if (s.substr(i,5)=="heavy") {
			hh++;
			i += 4;
		} else if (s.substr(i,5)=="metal") {
			cnt += hh;
			i += 4;
		}
	}
	printf("%lld", cnt);
}
