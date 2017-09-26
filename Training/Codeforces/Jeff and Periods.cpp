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
int n;
vpi v;
vi ret[100001];

int cmp(pi a, pi b) {
	if (b.second > a.second && b.first == a.first)
		return b.first < a.first;
	else {
		return a.first < b.first;
	}
}
int main() {
	file();
	scan(n);
	for (int i = 0; i < n; i++) {
		int x;
		scan(x);
		ret[x].push_back(i);
	}
	for (int i = 1; i <= 100000; i++) {
		if (!ret[i].size())
			continue;
		if (ret[i].size() == 1)
			v.push_back(make_pair(i, 0));
		else {
			int res = ret[i][1] - ret[i][0], flag = 1;
			for (int j = 2; j < ret[i].size(); j++) {
				flag &= (ret[i][j] - ret[i][j - 1]) == res;
			}
			if (flag)
				v.push_back(make_pair(i, res));
		}
	}
	printf("%d\n", v.size());
	for (auto i : v) {
		printf("%d %d\n", i.first, i.second);
	}
}
