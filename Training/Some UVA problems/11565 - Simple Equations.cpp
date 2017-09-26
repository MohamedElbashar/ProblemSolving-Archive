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
int n;
int main() {
	file();
	int n, a, b, c;
	scanf("%d", &n);
	while (n--) {
		scanf("%d%d%d", &a, &b, &c);
		int flag = 0;
		for (int i = -100; i <= 100; i++) {
			for (int j = -100; j <= 100; j++) {
				for (int k = -100; k <= 100; k++) {
					if (i != j && j != k && i != k && i + j + k == a
							&& i * j * k == b && i * i + j * j + k * k == c) {
						printf("%d %d %d\n", i, j, k);
						flag = 1;
						break;
					}
				}
				if (flag)
					break;
			}
			if (flag)
				break;
		}
		if (!flag)
			printf("No solution.\n");
	}
	return 0;
}

