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
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
#define oo 1e15
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
int flag2 = 1;
int solve(int i, int sum, int flag) {

	if (sum % 8 == 0 && flag) {
		printf("YES\n%d", sum);
		flag2 = 0;
		return 1;
	}
	if (i == s.size())
		return 0;
	if (!solve(i + 1, sum, flag) && !solve(i + 1, sum * 10 + (s[i] - '0'), 1)) {
		return 0;
	}
	return 1;
}
int main() {
	file();
	cin >> s;
	int x = solve(0, 0, 0);
	if (flag2)
		printf("NO");

}
