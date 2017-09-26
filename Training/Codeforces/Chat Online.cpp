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
int n, m, l, r, cnt;
vpi nn, mm;
bool check (pi xx , pi yy){
	if(xx.second < yy.first || yy.second < xx.first)
		return false;
	return true;
}

int main() {
	file();
	scanf("%d%d%d%d", &n, &m, &l, &r);
	rep(i,n)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		nn.push_back(make_pair(x, y));

	}
	rep(i,m)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		mm.push_back(make_pair(x, y));
	}
	for (int i = l; i <= r; i++) {
		for (int j = 0; j < n; j++) {
			int flag = 0;
			for (int k = 0; k < m; k++) {
				pi xx;
				xx.first = mm[k].first + i;
				xx.second = mm[k].second + i;
				if (check(xx,nn[j])) {
					cnt++;
					flag = 1;
					break;
				}
			}
			if (flag)
				break;
		}

	}
	cout << cnt;
}
