#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pi> vpi;
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define mem(a,b) memset(a,b,sizeof a)
#define sz(v) ((int)((v).size()))
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
	//freopen("sets.in", "r", stdin);
#endif
}
//\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\//\/\/\/\/\/\/\/\/\/\/
#define inRange(c, l, r) ((c >= l && c <= r) || (c >= r && c <= l))
#define max(x, y) ((x) > (y) ? (x) : (y))
struct seg {
	int sx, sy, ex, ey;
};
int t, n, q, i, x, y;
int main() {
	file();
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		seg s[100];
		for (int i = 0; i < n; i++) {
			scanf("%d%d%d%d", &s[i].sx, &s[i].sy, &s[i].ex, &s[i].ey);
		}
		scanf("%d", &q);
		while (q--) {
			scanf("%d%d", &x, &y);
			while (1) {
				int j = -1;
				double max = -1, ty;
				for (int i = 0; i < n; i++)
					if (inRange(x, s[i].sx, s[i].ex)) {
						ty = s[i].ey
								+ (double) (s[i].sy - s[i].ey) * (x - s[i].ex)
										/ (s[i].sx - s[i].ex);
						if (ty < y and ty > max)
							max = ty, j = i;
					}
				if (j == -1)
					break;
				if ((double) (s[j].sy - s[j].ey) / (s[j].sx - s[j].ex) < 0)
					x = max(s[j].sx, s[j].ex);
				else
					x = min(s[j].sx, s[j].ex);
				y = min(s[j].sy, s[j].ey);
			}
			printf("%d\n", x);
		}
		if (t)
			printf("\n");
	}
	return 0;
}
