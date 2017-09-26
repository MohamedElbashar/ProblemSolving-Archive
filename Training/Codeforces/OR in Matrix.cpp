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
int n, m, flag;
int b[101][101], a[101][101], c[101][101];
int main() {
	file();

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i][j] = 1;
	for (int i = 0; i < n; i++) {
		getchar();
		for (int j = 0; j < m; j++) {
			scanf("%d", &b[i][j]);
			if (b[i][j] == 0) {
				for (int k = 0; k < m; k++) {
					a[i][k] = 0;
				}
				for (int q = 0; q < n; q++) {
					a[q][j] = 0;
				}

			}
		}
	}
	/*for (int i = 0; i < n; i++) {
	 for (int j = 0; j < m; j++) {
	 printf("%d ", a[i][j]);
	 }
	 printf("\n");
	 }
	 printf("\n");
	 printf("\n");*/
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int ret = a[i][j];
			for (int k = 0; k < n; k++) {
				ret = ret or a[k][j];
			}
			for (int q = 0; q < m; q++) {
				ret = ret or a[i][q];
			}
			c[i][j] = ret;
		}
	}
	/*	for (int i = 0; i < n; i++) {
	 for (int j = 0; j < m; j++) {
	 printf("%d ", c[i][j]);
	 }
	 printf("\n");
	 }
	 return 0;*/

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (c[i][j] != b[i][j]) {
				flag = 1;
				break;
			}
		}
		if (flag) {
			printf("%s", "NO");
			return 0;
		}
	}
	printf("%s\n", "YES");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", a	[i][j]);
		}
		printf("\n");
	}

}
