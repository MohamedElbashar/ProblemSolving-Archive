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
int n, m;
char arr[500][500];
char temp[500][500];
char tst[500][500];
int cnt = 0, ans = 0;
vi v;
int solve() {
	ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - (m - 1); j++) {
			int flag = 1;
			for (int k = 0; k < m; k++) {
				for (int q = 0; q < m; q++) {
					if (arr[i + k][j + q] != tst[k][q]) {
						//cnt = 0;
						flag = 0;
						break;
					} else {
						cnt++;
					}
				}
				if (!flag) {
					break;
				}

			}
			if (cnt == m * m) {
				ans++;
			}
			cnt = 0;
		}
	}
	return true;
}
void transfooorm() {
	for (int j = n - 1; j >= 0; j--) {
		for (int i = 0; i < n; i++) {
			temp[n - (j + 1)][i] = arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = temp[i][j];
		}
	}
}
void clr() {
	cnt = 0;
	ans = 0;
	v.clear();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = 'T';
			temp[i][j] = 'P';
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			tst[i][j] = 'Q';
		}
	}
}
int main() {
	file();
	while (scanf("%d%d", &n, &m) && n && m) {
		for (int i = 0; i < n; i++) {
			scanf("%s", &arr[i]);
		}
		for (int i = 0; i < m; i++) {
			scanf("%s", &tst[i]);
		}
		solve();
		v.push_back(ans);
		for (int i = 0; i < 3; i++) {
			transfooorm();
			solve();
			v.push_back(ans);
		}
		printf("%d", v[0]);
		for (int i = 1; i < v.size(); i++) {
			printf(" %d", v[i]);
		}
		printf("\n");
		clr();
	}
}

