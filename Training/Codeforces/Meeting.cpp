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
int xa, ya, xb, yb, n, arr[1001][4], cnt;
double distance(int x, int y, int a, int b) {
	return sqrt(pow(x - a, 2) + pow(y - b, 2));
}
int main() {
	file();
	vpi v;
	set<pi> s;
	scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
	scan(n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &arr[i][0], &arr[i][1], &arr[i][2]);
	}

	int mnx = min(xa, xb);
	int mxx = max(xa, xb);
	int mny = min(ya, yb);
	int mxy = max(ya, yb);
	for (int j = mny; j <= mxy; j++) {
		for (int i = mnx; i <= mxx; i++) {
			if (i != xa && i != xb) {
				if (j != ya && j != yb)
					continue;
				else {
					v.push_back(make_pair(i, j));
				}
			} else {
				v.push_back(make_pair(i, j));
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < v.size(); j++) {
			double dis = distance(arr[i][0], arr[i][1], v[j].first,
					v[j].second);
			if (dis <= arr[i][2])
				s.insert(make_pair(v[j].first, v[j].second));
		}
	}
	cout << v.size() - s.size();

}
