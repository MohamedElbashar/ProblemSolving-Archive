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
int t1, t2, n, k, cnt;
vector<pair<int, double> > arr;
int cmp(pair<int, double> a, pair<int, double> b) {
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second > b.second;
}
int main() {
	file();
	scanf("%d%d%d%d", &n, &t1, &t2, &k);
	for (int i = 0; i < n; i++) {
		int xx, yy;
		scanf("%d%d", &xx, &yy);
		double perc = (double) (100 - k) / 100.;
		double mm = (double) max((xx * t1 * perc) + (yy * t2),
				(yy * t1 * perc) + (xx * t2));
		arr.push_back(make_pair(++cnt, mm));
	}
	sort(arr.begin(), arr.end(), cmp);
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i].first << "  " << fixed << setprecision(2)
				<< arr[i].second << endl;
	}
}

