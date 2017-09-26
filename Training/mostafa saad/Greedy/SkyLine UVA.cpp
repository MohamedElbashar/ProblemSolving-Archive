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
int a[20001], i, l, r, prv, h, mx, f;
int main() {
	file();
	while (scanf("%d%d%d", &l, &h, &r) != EOF) {
		if (l == -1)
			break;
		for (i = l; i < r; i++) {
			if (a[i] < h)
				a[i] = h;
		}
		mx = max(mx, r);
	}
	int flag = 1;
	for (int i = 0; i < sizeof a; i++) {
		cout << a[i] << " ";
	}
	return 0;
	for (i = 0, prv = 0; i <= mx + 1; i++) {
		if (prv != a[i]) {
			prv = a[i];
			if (flag) {
				printf("%d %d", i, prv);
				flag = 0;
				continue;
			}
			printf(" %d %d", i, prv);
		}
	}
	printf("\n");
	return 0;
}

