#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define PI 3.1415926535897932384626433832795
#define ll long long
#define mem(a,b) memset(a,b,sizeof a)
#define oo 1e8
#define minn(a, b, c) min(min(a, b), c)
#define maxx(a, b, c) max(max(a, b), c)
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int di[] = { 1, -1, 0, 0 };
int dj[] = { 0, 0, 1, -1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	// online submission
	//freopen("interesting.in", "r", stdin);
#endif
}
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\/\/\/\/\/\/
int main() {
	file();
	int n, l, w;
	double pos, r, ddx;
	while (scanf("%d%d%d", &n, &l, &w) != EOF) {
		vector<pair<double, double>> v;
		for (int i = 0; i < n; i++) {
			scanf("%lf%lf", &pos, &r);
			if (r > w / 2) {
				ddx = sqrt(r * r - w * w / 4.0);
				v.push_back( { (pos - ddx), (pos + ddx) });
			}
		}
		sort(v.begin(), v.end());
		int ch, flag = 0;
		double right = 0;
		int i, j;
		for (i = 0, j = 0; i < v.size(); i++) {
			double tmp = right;
			ch = -1;
			while (j < v.size() and v[j].first <= right) {
				if (v[j].second > tmp)
					tmp = v[j].second, ch = j;
				j++;
			}
			if (tmp >= l)
				printf("%d\n", i + 1), flag = 1, ch = -1;
			if (ch == -1)
				break;
			right = tmp;
		}
		if (!flag)
			puts("-1");
	}
	return 0;
}
