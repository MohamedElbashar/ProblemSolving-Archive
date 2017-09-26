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
#define all(v) v.begin(), v.end()
#define turnOnLastZero(S) ((S) | (S + 1))
#define maxx(a, b, c) max(max(a, b), c)
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int di[] = { 1, -1, 0, 0 };
int dj[] = { 0, 0, 1, -1 };
#define isOn(S, j) (S & (1 << j))
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
	int m, qq;
	scanf("%d", &m), scanf("%d", &qq);
	char db[1001][102], q[102];
	for (int i = 0; i < m && cin >> db[i]; ++i)
		;
	for (int i = 0; i < qq && cin >> q; ++i) {
		int ans = -1, mx = oo;
		for (int j = 0; j < m; ++j) {
			int md = oo;
			if (strlen(db[j]) >= strlen(q))
				for (int k = 0; k < strlen(db[j]); ++k) {
					if (k + strlen(q) <= strlen(db[j])) {
						int ddf = 0;
						for (int m = 0; m < strlen(q); ++m)
							if (q[m] != db[j][k + m])
								ddf++;
						md = min(ddf, md);
					}
				}
			if (md < mx)
				mx = md, ans = j + 1;
		}
		printf("%d\n", ans);
	}

	return 0;
}
