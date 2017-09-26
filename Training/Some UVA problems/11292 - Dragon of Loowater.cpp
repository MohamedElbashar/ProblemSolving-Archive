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
int n, m, x;
int main() {
	file();
	while (scanf("%d%d", &n, &m) && n && m) {
		vi dragon, knights;
		int res = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			dragon.push_back(x);
		}
		for (int i = 0; i < m; i++) {
			scanf("%d", &x);
			knights.push_back(x);
		}
		if (m < n) {
			printf("Loowater is doomed!\n");
			continue;
		}
		sort(dragon.begin(), dragon.end());
		sort(knights.begin(), knights.end());
		int i = 0, j = 0;	//i--> dragon ,, j--> knights
		for (; i < n && j < m; i++, j++) {
			while (dragon[i] > knights[j] && j < m)
				j++;
			if (j == m)
				break;
			res += knights[j];
		}
		if (i == n)
			printf("%d\n", res);
		else
			printf("Loowater is doomed!\n");

	}
	return 0;
}
