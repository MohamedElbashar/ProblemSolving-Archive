#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define ll long long
#define mem(a,b) memset(a,b,sizeof a)
#define oo 1e8
#define minn(a, b, c) min(min(a, b), c)
#define maxx(a, b, c) max(max(a, b), c)
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
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
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\/\/\/\/\/\/
int main() {
	file();
	int n, i, j, t;
	/*scanf("%*d",)
	 * accept integer and ignore it
	 * w b3de keda ast2bl el n fe while w 5alas :D
	 */
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int f[50] = { }, tmp;
		f[0] = 1;
		for (i = 2;; i++) {
			for (j = 0; j < n; j++) {
				tmp = f[j] + i;
				tmp = (int) sqrt(tmp);
				if (tmp * tmp == f[j] + i || f[j] == 0) {
					f[j] = i;
					break;
				}
			}
			if (j == n)
				break;
		}
		printf("%d\n", i - 1);

	}
	return 0;
}

