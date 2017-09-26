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
int killed[1025][1025];
int T, d, r, x, y, p, my;
int bound(int x, int y) {
	return x >= 0 && x < 1025 && y >= 0 && y < 1025;
}

int main() {
	file();
	scanf("%d", &T);
	while (T--) {
		memset(killed, 0, sizeof killed);
		scanf("%d", &d);
		scanf("%d", &r);
		while (r--) {
			scanf("%d %d %d", &x, &y, &p);
			for (int i = x - d; i <= x + d; i++)
				for (int j = y - d; j <= y + d; j++)
					if (bound(i, j))
						killed[i][j] += p;
		}
		my = -1;
		for (int i = 0; i < 1025; i++)
			for (int j = 0; j < 1025; j++) {
				if (killed[i][j] > my) {
					my = killed[i][j];
					x = i, y = j;
				}
			}

		printf("%d %d %d\n", x, y, my);
	}
}
